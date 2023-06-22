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
int k = 0, target = 0;

void rec(int level)
{
    if (level == n)
    {
        // Print the current permutation
        k++;
        if (k == target)
        {
            for (auto v : cur_per)
            {
                cout << v << " ";
            }
            cout << endl;
        }
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
    cin >> n >> target;
    int arr[n];
    mp.clear();
    k = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
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