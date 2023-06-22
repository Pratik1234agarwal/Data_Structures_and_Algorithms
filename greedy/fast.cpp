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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        a[i] = r;
        arr.push_back({r, i});
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    int rates[n] = {0};

    for (int i = 0; i < n; i++)
    {
        int rating = arr[i].first;
        int index = arr[i].second;

        if (index != n - 1)
        {
            if (a[index + 1] < rating)
            {
                sum += rates[index + 1] + 1;
                rates[index] = rates[index + 1] + 1;
            }
            else
            {
                sum += 1;
                rates[index] = 1;
            }
        }
        else if (index != 0)
        {
            if (a[index - 1] < rating)
            {
                sum += rates[index - 1] + 1;
                rates[index] = rates[index - 1] + 1;
            }
            else
            {
                sum += 1;
                rates[index] = 1;
            }
        }
    }

    cout << sum << endl;
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