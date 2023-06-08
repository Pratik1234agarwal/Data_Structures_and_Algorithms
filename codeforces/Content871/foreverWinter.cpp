#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mpii = map<int, int>;

#define endl '\n'

void solve()
{

    int n, m;
    cin >> n >> m;
    vi g;
    g.resize(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x]++;
        g[y]++;
    }

    int u1, u2, u3;
    int c1 = 0, c2 = 0, c3 = 0;
    int flag = 1;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int r = g[i];
        if (mp.find(r) != mp.end())
            mp[r]++;
        else
        {
            mp[r] = 1;
        }
    }

    int x;
    for (auto v : mp)
    {
        if (v.second == 1)
        {
            x = v.first;
        }
    }

    int y = mp[1] / x;

    cout << x << " " << y << endl;
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