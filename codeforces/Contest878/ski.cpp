#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int head = -1, tail = 0;
    int distinct = 0;
    map<int, int> st;
    lli ans = 0;
    int count = 0;
    while (tail < n)
    {
        // move head as far as possible
        while (head + 1 < n && arr[head + 1] <= q)
        {
            head++;
            count++;
        }

        int nLen = count;

        if (nLen >= k)
        {
            int x = nLen - k;
            ans += (x + 1);
        }

        if (head >= tail)
        {
            count--;
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }

    cout << ans << endl;
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