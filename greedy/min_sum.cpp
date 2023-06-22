#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vii = vector<vi>;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << b[i] << endl;
        sum += abs(a[i] - b[i]);
    }

    cout << sum << endl;
}

int main()
{
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}