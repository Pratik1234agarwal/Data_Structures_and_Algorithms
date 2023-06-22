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
    ll x, y;
    cin >> x >> y;

    ll temp = y;
    ll count = 0;

    if (y > x && y % 2 == 1)
    {
        count++;
        temp += 1;
    }

    while (temp > x)
    {
        temp /= 2;
        count++;
    }

    count += (x - temp);
    cout << count << endl;
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