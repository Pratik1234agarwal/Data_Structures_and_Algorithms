#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using ll = long long int;
using pll = pair<ll, ll>;
using mpii = map<int, int>;
using mpll = map<ll, ll>;
using si = set<int>;

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
    int r = 3.4 / 1;
    cout << r << endl;
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