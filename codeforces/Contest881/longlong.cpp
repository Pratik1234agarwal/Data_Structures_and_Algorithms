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
    int n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    int c = 0, flag = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {

            sum += -1LL * arr[i];
            if (flag)
            {
                c++;
            }
            flag = 0;
        }
        else if (arr[i] > 0)
        {
            flag = 1;
            sum += arr[i];
        }
    }

    cout << sum << " " << c << endl;
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