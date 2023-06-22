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
#define INF 1e18

int n, m;
int minCount = 1e9;

vector<ll> d;
vi cnt;

void dfs(int node, vector<vector<pii>> g, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi vis(n + 1, 0);
    vector<ll> dis(n + 1, INF);

    dis[node] = 0;
    pq.push({0, node});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int u = it.S;
        int curDis = it.F;

        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto x : g[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v] > curDis + w)
            {
                d[v] = curDis + w;
                pq.push({d[v], v});
                cnt[v] = cnt[u] + 1;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    vector<vector<pii>> g(n + 1, vector<pii>{});
    d.assign(n + 1, INF);
    cnt.assign(n + 1, 0);

    vi vis(n + 1, 0);

    minCount = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 1}); // forward links
        g[y].push_back({x, 2}); // back links
    }

    dfs(1, g, n);
    if (d[n] == INF)
    {
        cout << -1 << endl;
    }
    else
        cout << d[n] - cnt[n] << endl;
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