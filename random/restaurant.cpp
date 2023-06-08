#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

struct Order
{
    int orderId;
    int timeRemaining;
    int nItems;
    list<string> items;
    bool operator<(Order order)
    {
        return timeRemaining < order.timeRemaining;
    }
    bool operator==(Order order)
    {
        return orderId == order.orderId;
    }
};

struct ItemKitchen
{
    int cookTime;
    string itemName;
    bool operator<(ItemKitchen item)
    {
        return cookTime < item.cookTime;
    }
    bool operator==(ItemKitchen item)
    {
        return item.cookTime == cookTime && itemName == item.itemName;
    }
};

struct CompareById
{
    // Compare 2 Player objects using name
    bool operator()(const Order &o1, const Order &o2)
    {
        return o1.orderId < o2.orderId;
    }
};

list<Order> orders;
list<ItemKitchen> cookingQueue, cooked;
int TIME_ELAPSED = 0;

void add_order(Order order)
{
    orders.push_back(order);
    orders.sort();
    // return orders;
}

void add_item(ItemKitchen item)
{
    cookingQueue.push_back(item);
    cookingQueue.sort();
}

void fulfil_expire_order()
{

    list<Order> tempList;
    for (const Order &o : orders)
    {
        if (o.timeRemaining - TIME_ELAPSED >= 0)
        {
            // Fullfil Order if possible
            int f = 0;
            if (o.items.size() > cooked.size())
            {
                continue;
            }
            list<ItemKitchen> temp;
            for (const string item : o.items)
            {
                f = 0;

                for (const ItemKitchen &tt : cooked)
                {
                    if (tt.itemName == item)
                    {
                        f = 1;
                        temp.push_back(tt);
                        break;
                    }
                }

                if (f == 0)
                {
                    // All Items are not satisfied
                    break;
                }
            }

            if (f == 1)
            {
                // All Items present
                std::cout << "Filled order #" << o.orderId << endl;
                // orders.remove(o);
                tempList.push_back(o);
                for (const ItemKitchen &ii : temp)
                {
                    cooked.remove(ii);
                    cout << "Removed a " << ii.itemName << "extra-large-pepperoni from completed items." << endl;
                }
            }
        }
        else
        {
            // Order has expired
            std::cout << "Order # " << o.orderId << " expired." << endl;
            // orders.remove(o);
            tempList.push_back(o);
        }
    }

    for (Order oo : tempList)
    {
        orders.remove(oo);
    }
}

void run_until_next()
{
    std::cout << "Running until next event." << endl;
    if (cookingQueue.size() > 0)
    {
        ItemKitchen item = cookingQueue.front();
        std::cout << "Finished cooking " << item.itemName << endl;
        std::cout << item.cookTime << " minute(s) have passed." << endl;
        cookingQueue.remove(item);
        cooked.push_back(item);
        TIME_ELAPSED += item.cookTime;
    }
    else if (orders.size() > 0)
    {
        Order temp = orders.front();
        std::cout << "Order # " << temp.orderId << " expired." << endl;
        orders.remove(temp);
        TIME_ELAPSED += temp.timeRemaining;
    }
    else
    {
        std::cout << "No events waiting to process." << endl;
    }
}

void run_for_time(int runningTime)
{
    std::cout << "===Starting run of " << runningTime << " minute(s)===" << endl;
    while (runningTime > 0)
    {
        for (ItemKitchen &iii : cookingQueue)
        {
            cout << "item :" << iii.itemName << " time: " << iii.cookTime << endl;
        }
        if (cookingQueue.size() > 0)
        {
            ItemKitchen firstItem = cookingQueue.front();
            if (firstItem.cookTime <= runningTime)
            {
                runningTime -= firstItem.cookTime;
                TIME_ELAPSED += firstItem.cookTime;
                cout << "Finished cooking " << firstItem.itemName << endl;
                cooked.push_back(firstItem);
                cookingQueue.remove(firstItem);
                continue;
            }
            else
            {
                firstItem.cookTime -= runningTime;
                TIME_ELAPSED += runningTime;
                runningTime = 0;
            }
        }
        else
        {
            TIME_ELAPSED += runningTime;
            runningTime = 0;
        }

        // Operation with Order FULLFILEMT OR EXPIRY
        fulfil_expire_order();
    }
    std::cout << "===Run for specified time is complete===" << endl;
}

void print_order_by_time()
{
    cout << "Printing " << orders.size() << " order(s) by promised time remaining:" << endl;
    for (const Order o : orders)
    {
        cout << "  #" << o.orderId << " (" << o.timeRemaining << " minute(s) left):" << endl;
        for (string str : o.items)
        {
            cout << "\t" << str << endl;
        }
    }
}

void print_order_by_id()
{
    cout << "Printing " << orders.size() << " order(s) by ID:" << endl;
    orders.sort(CompareById());
    for (const Order o : orders)
    {
        cout << "  #" << o.orderId << " (" << o.timeRemaining << " minute(s) left):" << endl;
        for (string str : o.items)
        {
            cout << "\t" << str << endl;
        }
    }

    orders.sort();
}

void print_kitchen_is_cooking()
{
    cout << "Printing " << cookingQueue.size() << " items being cooked:" << endl;
    for (ItemKitchen &ii : cookingQueue)
    {
        cout << "\t" << ii.itemName << " (" << ii.cookTime << " minute(s) left)" << endl;
    }
}

void print_kitchen_has_completed()
{
    cout << "Printing " << cooked.size() << " completely cooked items:" << endl;
    for (ItemKitchen &ii : cooked)
    {
        cout << "\t" << ii.itemName << endl;
    }
}

int main()
{

    string str;
    stringstream ss;

    // freopen("output.txt", "w", stdout);

    do
    {
        str = "";
        getline(cin, str);
        ss.clear();
        ss << str;
        string firstWord;
        ss >> firstWord;

        if (firstWord == "add_order")
        {
            int id, time, nItems;
            ss >> id >> time >> nItems;
            cout << "Received new order #" << id << " due in " << time << " minute(s):"
                 << endl;

            Order order;
            order.orderId = id;
            order.timeRemaining = time;
            order.nItems = nItems;
            for (int i = 1; i <= nItems; i++)
            {

                string itemName;
                ss >> itemName;
                order.items.push_back(itemName);
            }
            for (string &str : order.items)
            {
                cout << "\t" << str << endl;
            }
            add_order(order);
        }
        else if (firstWord == "add_item")
        {
            int time;
            string itemName;
            ss >> time >> itemName;
            ItemKitchen item;
            item.cookTime = time;
            item.itemName = itemName;
            add_item(item);
            cout << "Cooking new " << itemName << " with " << time << " minute(s) left." << endl;
        }
        else if (firstWord == "run_until_next")
        {
            run_until_next();
        }
        else if (firstWord == "run_for_time")
        {
            int time;
            ss >> time;
            run_for_time(time);
        }
        else if (firstWord == "print_orders_by_time")
        {
            print_order_by_time();
        }
        else if (firstWord == "print_orders_by_id")
        {
            print_order_by_id();
        }
        else if (firstWord == "print_kitchen_is_cooking")
        {
            print_kitchen_is_cooking();
        }
        else if (firstWord == "print_kitchen_has_completed")
        {
            print_kitchen_has_completed();
        }
        else
        {
            cout << "error" << endl;
        }

    } while (!str.empty());
    cout << "End of Input File" << endl;
}