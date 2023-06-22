#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        int r;
        cin >> r;
        s ^= r;
    }

    if (n % 2 == 0)
    {
        cout << 0 << endl;
    }
    else
        cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}