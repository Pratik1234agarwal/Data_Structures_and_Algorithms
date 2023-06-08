#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve()
{
    int q;
    cin >> q;
    int n = 0;
    int arr[60] = {0};
    int flag;
    int cnt = 0;
    lli val = 0;
    while (q--)
    {
        int t;
        cin >> t;
        int x;
        switch (t)
        {
        case 1:
            cin >> x;
            // cout << (n >> x & 1) << endl;
            cout << arr[x] << endl;
            break;
        case 2:
            cin >> x;
            // n = (n | 1 << x);
            arr[x] = 1;
            break;
        case 3:
            cin >> x;
            // if (!((n >> x) & 1))
            // {
            //     n = n ^ (1 << x);
            // }
            arr[x] = 0;
            break;
        case 4:
            cin >> x;
            // n = n ^ (1 << x);
            arr[x] = arr[x] ^ 1;
            break;
        case 5:
            flag = 0;
            for (auto a : arr)
            {
                if (a == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }

            break;

        case 6:
            flag = 0;
            for (auto a : arr)
            {
                if (a == 1)
                {
                    flag = 1;
                    break;
                }
            }

            cout << flag << endl;
            break;
        case 7:
            flag = 1;
            for (auto a : arr)
            {
                if (a == 1)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }

            break;
        case 8:
            cnt = 0;
            for (auto a : arr)
                cnt += a;
            cout << cnt << endl;
            break;

        case 9:
            val = 0;
            for (int i = 0; i < 60; i++)
            {
                val += arr[i] * (1 << i);
            }
            cout << val << endl;
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}