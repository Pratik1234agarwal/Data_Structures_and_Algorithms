#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
    vector<int> queue;
    int len;
    int front,back;
public:
    
    MyCircularQueue(int k)
    {
        queue.resize(k);
        len = k;
        front=0;back=0;
    }

    bool enQueue(int value)
    {
        if(isFull()){
            return false;
        }else{
        	back = (back + 1)%len;
            queue[back] = value;
            return true;
        }
    }

    bool deQueue()
    {
        if(isEmpty()){
            return false;
        }else{
            front = (front+1)%len;
        }
    }

    int Front()
    {
     	if(isEmpty())return -1;
        return queue[front];
    }

    int Rear()
    {
        if(isEmpty())return -1;
        return queue[back];
    }

    bool isEmpty()
    {
        return front == back;
    }

    bool isFull()
    {
        if(front == 0 && back == len-1){
            return true;
        }else if(back == front-1){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularQueue myCircularQueue(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "enQueue")
        {
            int val;
            cin >> val;

            if (myCircularQueue.enQueue(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deQueue")
        {
            if (myCircularQueue.deQueue())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "Front")
        {
            cout << myCircularQueue.Front() << "\n";
        }
        else if (s == "Rear")
        {
            cout << myCircularQueue.Rear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularQueue.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularQueue.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}