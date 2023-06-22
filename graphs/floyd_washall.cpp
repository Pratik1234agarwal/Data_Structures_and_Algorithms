#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using ll = long long int;
using pll = pair<ll, ll>;
using mpii = map<int, int>;
using mpll = map<ll, ll>;

#define F first
#define S second
#define endl '\n'

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b, b % a);
}

pll get_red_frac(ll x, ll y)
{
    if (x == 0 && y == 0)
        return {0, 0};
    if (x == 0 && y != 0)
        return {0, 1};
    if (x != 0 && y == 0)
        return {1, 0};
    int neg = 1;
    if (x < 0)
    {
        neg *= -1, x = -1 * x;
    }
    if (y < 0)
    {
        neg *= -1;
        y *= -1;
    }

    ll a = gcd(x, y);
    return make_pair(neg * (x / a), y / a);
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    ll dis[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != j)
                dis[i][j] = 1e18;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(1LL * c, dis[a][b]);
        dis[b][a] = min(1LL * c, dis[a][b]);
    }

    // Main Algo
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // Running q queries
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == 1e18)
            cout << -1 << endl;
        else
            cout << dis[a][b] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}