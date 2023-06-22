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

void solve()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n);

    int median = n / 2;
    int xMid = x[median], yMid = y[median];
    ll dis = 0;
    for (int i = 0; i < n; i++)
    {
        dis += abs(x[i] - xMid) + abs(y[i] - yMid);
    }

    cout << dis << endl;
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