#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mapii = map<int, int>;

#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ss;
    char ori = '\0';
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ori == '\0')
        {
            ori = ch;
            ss += ch;
        }

        do
        {
            i++;
            ch = str[i];
        } while (ch != ori && i < n);
        ori = '\0';
    }

    cout << ss << endl;
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