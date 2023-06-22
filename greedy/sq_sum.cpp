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
    ll sum = 0;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll avg1 = ceil(sum / n);
    ll avg2 = floor(sum / n);

    ll val1 = 0, val2 = 0;
    for (int i = 0; i < n; i++)
    {
        ll s1 = (avg1 - arr[i]) * (avg1 - arr[i]);
        ll s2 = (avg2 - arr[i]) * (avg2 - arr[i]);
        val1 += s1;
        val2 += s2;
    }

    cout << min(val1, val2) << endl;
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