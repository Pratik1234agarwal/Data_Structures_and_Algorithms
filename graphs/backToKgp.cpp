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

int n, m;
vector<vector<pii>> g;
ll minDistance = 1e18;
int nMins = -1;
int nMaxFlights = 0;
int nMinFlights = 0;
vector<int> d;

vector<int> curVisited;

void dfs(int source, int destination, ll dis, int nFlights)
{
    if (source == destination)
    {
        if (dis < minDistance)
        {
            minDistance = dis;
            nMins = 1;
            nMaxFlights = nFlights;
            nMinFlights = nFlights;
        }
        else if (dis == minDistance)
        {
            nMins++;
            nMaxFlights = max(nFlights, nMaxFlights);
            nMinFlights = min(nFlights, nMinFlights);
        }

        return;
    }

    for (auto it : g[source])
    {
        int w = it.S;
        int v = it.F;
        ll ndis = w + dis;
        dfs(v, destination, ndis, nFlights + 1);
    }
}

void solve()
{
    cin >> n >> m;
    g.assign(n + 1, vector<pii>{});
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dfs(1, n, 0, 0);

    if (minDistance == 1e18)
        cout << minDistance << " " << nMins << " " << nMinFlights << " " << nMaxFlights << endl;
    else
        cout << -1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}