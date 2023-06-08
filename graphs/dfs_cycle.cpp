#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

// Global Variables
vii g;
vi vis;
int n, m;

int cnt;
vi comp_sizes;
vi dis;

void explore(int node)
{
    // Marked Visited
    vis[node] = 1;
    cnt++;

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            explore(v);
        }
    }
}

void dfs()
{
    vis.assign(n + 1, 0);
    dis.assign(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            explore(i);
            comp_sizes.push_back(cnt);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);

    // Storing Graph
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // DFS
    dfs();

    for (auto s : comp_sizes)
    {
        cout << s << " ";
    }
}

signed main()
{
    solve();
}