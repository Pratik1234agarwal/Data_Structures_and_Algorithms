#include <bits/stdc++.h>
using namespace std;

int n, m, _q;
vector<vector<int>> g;

vector<int> vis;
queue<int> q;

vector<int> ancestors;
vector<int> dis;

int comp_num = 0;
// vector<int> comp_sizes;

int CYCLE_PRESENT = 0;

void explore(int s)
{
    comp_num++;
    int nodes_explored = 0;

    q.push(s);
    vis[s] = comp_num;
    nodes_explored++;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto v : g[x])
        { // for all neighbours of node x.
            if (!vis[v])
            {
                q.push(v);
                ancestors[v] = x;
                vis[v] = comp_num;
                dis[v] = dis[x] + 1;
                nodes_explored++;
            }
            else
            {
                if (ancestors[x] != v)
                {
                    // Cycle Detected
                    cout << "Cycle Found" << endl;
                    cout << "Length of Cycle: " << dis[x] - dis[v] << endl;
                    cout << "X: " << x << " V: " << v << endl;
                    CYCLE_PRESENT = 1;
                }
            }
        }
    }
}

void bfs()
{
    vis.assign(n + 1, 0);
    ancestors.assign(n + 1, -1);
    dis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            explore(i);
        }
    }
}

int nc2(int n)
{
    return n * (n - 1) / 2;
}

void solve()
{

    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // find the components and their sizes.
    bfs();

    cout << "Ancestors : " << endl;
    for (auto i : ancestors)
    {
        cout << i << " ";
    }
    cout << endl;

    if (CYCLE_PRESENT)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{
    solve();
}