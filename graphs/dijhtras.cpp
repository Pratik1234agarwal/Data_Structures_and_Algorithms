#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 100001;
using pii = pair<int, int>;
using ll = long long int;
using pll = pair<ll, ll>;

vector<pair<int, ll>> graph[N];
vector<ll> dis;
vector<bool> vis;

#define INF 1e18

void dijktra(int n, int source)
{
    priority_queue<pll, vector<pll>, greater<pll>> q;
    vis.assign(n + 1, false);
    dis.assign(n + 1, INF);

    dis[source] = 0;
    q.push({0, source});

    while (!q.empty())
    {
        pll node = q.top();
        int u = node.second;
        ll curDis = node.first;
        q.pop();

        if (vis[u])
            continue;

        vis[u] = true;

        for (auto cur : graph[u])
        {
            int v = cur.first;
            ll w = cur.second;

            if (dis[v] > w + curDis)
            {
                dis[v] = w + curDis;
                q.push({dis[v], v});
            }
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source = 1;

    dijktra(n, source);

    int destination;
    cin >> destination;

    cout << dis[destination] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}