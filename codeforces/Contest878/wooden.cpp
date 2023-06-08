#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mpii = map<int, int>;

#define endl '\n'

int check(int arr[], int n, int x)
{
    int nWorkers = 1;
    int workerSum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        int len = (end + 1) - start;
        if (((workerSum + arr[i]) / len) <= x && end + 1 < n)
        {
            end++;
            workerSum += arr[i];
        }
        else
        {
            workerSum = arr[i];
            if (arr[i] > x)
                return 0;
            start = end + 1;
            end++;
            nWorkers++;
        }
    }

    if (nWorkers <= 3)
        return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);

    lli left = 0, right = sum;
    lli ans = sum;
    while (left <= right)
    {
        lli mid = left + (right - left) / 2;
        if (check(arr, n, mid))
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

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}