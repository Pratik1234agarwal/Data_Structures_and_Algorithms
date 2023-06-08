#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mpii = map<int, int>;

#define endl '\n'

int explore(int a, int b)
{
    if (a == b)
        return 1;

    if (a % 3 != 0)
        return 0;

    int dd = a / 3;
    int n1 = dd, n2 = 2 * dd;
    return explore(n1, b) + explore(n2, b);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "YES" << endl;
        return;
    }
    if (a % 3 != 0 || b > a)
    {
        cout << "NO" << endl;
        return;
    }

    // Answer might exist as b < a and a is a divisor of 3
    int possible = explore(a, b);

    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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