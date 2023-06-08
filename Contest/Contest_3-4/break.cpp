#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve()
{
    int n;
    lli k;
    cin >> n >> k;

    // i -> (1,k)
    //  get the max element from arr
    //  break into a/2 and a - a/2 and insert into arr
    // return the max element of the array

    // Efficient

    // i -> (32,1)
    //   loop through array, find which element is >= 1<<i
    //   replace these elements with n/2 and n - n/2 and reduce k by 1
    //   update the max element
    //   if k == 0 break and return the max element
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