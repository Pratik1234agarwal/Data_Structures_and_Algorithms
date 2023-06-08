#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int check(lli arr[], int n, lli x, int k)
{
    lli sumUntilNow = 0;
    int divisions = 1;
    for (int i = 0; i < n; i++)
    {
        if (sumUntilNow + arr[i] <= x)
        {
            sumUntilNow += arr[i];
        }
        else
        {
            sumUntilNow = arr[i];
            if (sumUntilNow > x)
                return 0;
            divisions++;
        }
    }

    if (divisions <= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    lli arr[n];
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    lli left = 0, right = sum;
    lli ans = sum;
    while (left <= right)
    {
        lli mid = left + (right - left) / 2;

        if (check(arr, n, mid, k))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}