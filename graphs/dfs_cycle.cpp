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
vi ancestors;

vi cycle_sizes;

void explore(int node)
{
    // Marked Visited
    vis[node] = 1;
    cnt++;

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dis[v] = dis[node] + 1;
            ancestors[v] = node;
            explore(v);
        }
        else
        {
            if (v != ancestors[node] && ancestors[node] != -1)
            {

                int len = dis[node] - dis[v] + 1;
                // cout << "Cycle Found with length : " << len << " First : " << v << " End: " << node << endl;
                if (len % 2 != 0)
                {
                    cycle_sizes.push_back(len);
                }
            }
        }
    }
}

void dfs()
{
    vis.assign(n + 1, 0);
    dis.assign(n + 1, 1e9);
    ancestors.assign(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            dis[i] = 0;
            ancestors[i] = -1;
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

    if (!cycle_sizes.empty())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

signed main()
{
    solve();
}