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
    vector<pii> arr;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    ll cStart = arr[0].first, cEnd = arr[0].second;
    ll uniques = 1;
    for (int i = 1; i < n; i++)
    {
        ll a = arr[i].first, b = arr[i].second;
        if (a <= cEnd)
        {
            cStart = a;
            cEnd = min(cEnd, b);
        }
        else
        {
            uniques++;
            cStart = a;
            cEnd = b;
        }
    }

    cout << uniques << endl;
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