#include <bits/stdc++.h>
using namespace std;

int solve()
{
    string s;
    cin >> s;
    string ss = "codeforces";
    int different = 0;
    for (int i = 0; i < 10; i++)
    {
        if (s[i] != ss[i])
            different++;
    }

    cout << different << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}