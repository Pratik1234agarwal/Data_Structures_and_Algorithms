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

bool comp(pii a, pii b)
{
    return (a.F - a.S) > (b.F - b.S);
}

void solve()
{
    int n;
    cin >> n;
    pii arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, comp);

    ll nSoldiers = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i].first;
        int nr = cur - prev;
        nSoldiers += nr;

        prev = cur - arr[i].S;
    }

    cout << nSoldiers << endl;
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