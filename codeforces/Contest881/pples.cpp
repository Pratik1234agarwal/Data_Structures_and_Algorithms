#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using ll = long long int;
using pll = pair<ll, ll>;

#define F first
#define S second
#define endl '\n'

vii g;
vi tt;
vi vis;

ll explore(int node)
{
    vis[node] = 1;
    if (g[node].size() == 1 && node != 1)
    {
        tt[node] = 1;
    }
    else
    {

        for (auto ch : g[node])
        {
            if (!vis[ch])
            {
                tt[node] += explore(ch);
            }
        }
    }
    vis[node] = 0;
    return tt[node];
}

void solve()
{
    int n;
    cin >> n;

    g.assign(n + 1, vi{});
    tt.assign(n + 1, 0);
    vis.assign(n + 1, 0);

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    explore(1);

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (1LL * tt[a] * tt[b]) << endl;
    }
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