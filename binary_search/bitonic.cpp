#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli *arr;
int n;

int check(int index)
{
    if (index == n - 1)
        return 1;
    if (arr[index] > arr[index + 1])
    {
        return 1;
    }
    return 0;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    arr = new lli[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;
    lli ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    // ans point to the the peak of the array

    while (q--)
    {
        int k;
        cin >> k;

        left = 0;
        right = ans - 1;
        int leftAns = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
            {
                leftAns = mid;
                break;
            }
            else if (arr[mid] > k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (leftAns != -1)
        {
            cout << leftAns + 1 << " ";
        }

        left = ans;
        right = n - 1;
        int rAns = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
            {
                rAns = mid;
                break;
            }
            else if (arr[mid] > k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (rAns != -1)
        {
            cout << rAns + 1;
        }

        cout << endl;
    }

    delete[] arr;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}