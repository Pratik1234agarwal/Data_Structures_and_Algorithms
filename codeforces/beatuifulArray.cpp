#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int flag = 0;
    int nOdds = 0, nEvens = 0;

    for (int i = 0; i < n; i++)
    {
        int r = arr[i];

        if ((nEvens > 0 || arr[i] % 2 == 0) && (nOdds > 0 || arr[i] % 2 == 1))
        {
            if (nOdds > 0)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        if (r % 2 == 0)
            nEvens++;
        else
            nOdds++;
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}