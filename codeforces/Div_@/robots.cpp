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
    int arr[n];
    int cc[1000] = {0};
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cc[arr[i]]++;
        m = max(m, arr[i]);
    }

    int flag = 0;
    for (int i = 1; i <= m; i++)
    {
        if (cc[i] > cc[i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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