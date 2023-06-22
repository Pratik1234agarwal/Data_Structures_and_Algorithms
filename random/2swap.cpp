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
    string a, b;
    cin >> a >> b;
    multiset<char> even, odd;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even.insert(a[i]);
        }
        else
        {
            odd.insert(a[i]);
        }
    }

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = b[i];
        if (i % 2 == 0)
        {
            if (even.find(ch) == even.end())
            {
                flag = 1;
                break;
            }
            else
            {
                even.erase(ch);
            }
        }
        else
        {
            if (odd.find(ch) == odd.end())
            {
                flag = 1;
                break;
            }
            else
            {
                odd.erase(ch);
            }
        }
    }

    if (flag == 0 && even.empty() && odd.empty())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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