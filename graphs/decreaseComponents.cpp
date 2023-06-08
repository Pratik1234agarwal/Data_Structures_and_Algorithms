#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;

vector<int> isVisited;
vector<int> comp_sizes;
queue<int> q;
int componentNumber = 0;
map<int, int> mp;

void explore(int x)
{
    // New Component Found
    componentNumber++;

    int nodesExplored = 0;
    isVisited[x] = 1;
    nodesExplored++;
    q.push(x);
    mp[x] = componentNumber;
    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        for (auto v : g[e])
        {
            if (!isVisited[v])
            {
                q.push(v);
                isVisited[v] = 1;
                nodesExplored++;
                mp[x] = componentNumber;
            }
        }
    }

    comp_sizes.push_back(nodesExplored);
}

void bfs()
{
    isVisited.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            explore(i);
        }
    }
}

int solve()
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

    // Find the number of Components and their sizes
    // Use DFS and BFS
    bfs();

    int q;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}