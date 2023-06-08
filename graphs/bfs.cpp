#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;

vector<int> isVisited;
vector<int> comp_sizes;
queue<int> q;

void explore(int x)
{
    int nodesExplored = 0;
    isVisited[x] = 1;
    nodesExplored++;
    q.push(x);
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

    // Calculate all pair sums
    int ans = 0;
    int sum = 0;
    for (auto v : comp_sizes)
    {
        ans += sum * v;
        sum += v;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}