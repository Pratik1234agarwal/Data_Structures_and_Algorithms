#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        arr[i] = r;
    }

    for (int i = 0; i < k; i++)
    {
        int ch, x;
        cin >> ch >> x;
        auto low = lower_bound(arr.begin(), arr.end(), x);
        auto up = upper_bound(arr.begin(), arr.end(),x);
        if (ch == 1)
        {
            // find with a binary search
            if (up != arr.end() && low != arr.begin())
            {
                if (*(up - 1) == *(low + 1))
                {
                    int pos = (up - 1) - arr.begin() + 1;
                    cout << pos << " ";
                }
                else
                {
                    int pos = up - arr.begin() + 1;
                    cout << pos << " ";
                }
            }
            else
            {
                cout << -1 << " ";
            }
            // get the upper bound if not found
        }
        else if (ch == 2)
        {
            // upper bound
            if (up == arr.end())
            {
                cout << -1 << " ";
            }
            else
            {
                int pos = (up - arr.begin()) + 1;
                cout << pos << " ";
            }
        }
        else if (ch == 3)
        {
            // binary search
            if (up != arr.end() && low != arr.begin())
            {
                if (*(up - 1) == *(low + 1))
                {
                    int pos = (low + 1) - arr.begin() + 1;
                    cout << pos << " ";
                }
                else
                {
                    int pos = low - arr.begin() + 1;
                    cout << pos << " ";
                }
            }
            else
            {
                cout << -1 << " ";
            }
            // lower bound if not found
        }
        else
        {
            // lower bound
            if (low == arr.begin())
            {
                cout << -1 << " ";
            }
            else
            {
                int pos = (low - arr.begin()) + 1;
                cout << pos << " ";
            }
        }
    }

    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;cin>>_t;while(_t--)
    solve();
}