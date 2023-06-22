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

int n;
vi cur_per;
map<int, int> mp;

void rec(int level)
{
    if (level == n)
    {
        // Print the current permutation
        for (auto v : cur_per)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    else
    {
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                mp[it.first]--;
                cur_per.push_back(it.first);
                rec(level + 1);
                cur_per.pop_back();
                mp[it.first]++;
            }
        }
    }
}

void solve()
{
    cin >> n;
    int arr[n];
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    rec(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}