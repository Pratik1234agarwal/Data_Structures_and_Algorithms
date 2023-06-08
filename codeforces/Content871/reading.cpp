#include <bits/stdc++.h>
#include <string>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mpii = map<int, int>;

#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int m1 = 1e9, m2 = 1e9, total = 1e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        string ss;
        cin >> x >> ss;
        int a1 = (ss[0] - '0'), a2 = (ss[1] - '0');
        if (a1 == 1 && a2 == 0)
        {
            m1 = min(m1, x);
            total = min(total, m1 + m2);
        }
        else if (a1 == 0 && a2 == 1)
        {
            m2 = min(m2, x);
            total = min(total, m1 + m2);
        }
        else if (a1 == 1 && a2 == 1)
        {
            total = min(total, x);
        }
    }
    if (total == 1e9)
        cout << -1 << endl;
    else
        cout << total << endl;
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