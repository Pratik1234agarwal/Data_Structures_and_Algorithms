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

bool oddBits(int x)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        int aa = (x >> i) & 1;
        if (aa == 1)
        {
            count++;
        }
    }
    return count % 2;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int head = -1, tail = 0;
    int curXor = 0;
    ll sum = 0;
    while (tail < n)
    {

        while (head + 1 < n && oddBits(curXor ^ arr[head + 1]))
        {
            head++;
            curXor ^= arr[head];
        }

        // cout << head << " " << tail << endl;

        sum += (head - tail) + 1;

        if (head > tail)
        {
            curXor ^= arr[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
            curXor = 0;
        }
    }

    cout << sum << endl;
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