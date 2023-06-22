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

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b, b % a);
}

pll get_red_frac(ll x, ll y)
{
    if (x == 0 && y == 0)
        return {0, 0};
    if (x == 0 && y != 0)
        return {0, 1};
    if (x != 0 && y == 0)
        return {1, 0};
    int neg = 1;
    if (x < 0)
    {
        neg *= -1, x = -1 * x;
    }
    if (y < 0)
    {
        neg *= -1;
        y *= -1;
    }

    ll a = gcd(x, y);
    return make_pair(neg * (x / a), y / a);
}

void solve()
{
    int n, m;
    vector<pii> st, stt;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        st.push_back({a, b});
        stt.push_back({b, a});
    }

    sort(st.begin(), st.end());
    sort(stt.begin(), stt.end());

    int q;
    cin >> q;
    int left = 0, right = 0;
    int nZeros = 0, nOnes = 0;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (left == 0 && right == 0)
        {
            left = x;
            right = x;
            nOnes = 1;
            nZeros = 0;
        }
        else
        {
            if (x < left)
            {
                int t = left - x - 1;
                nZeros += t;
                nOnes++;
                left = x;
            }
            else if (x > right)
            {
                int t = x - right - 1;
                nZeros += t;
                nOnes++;
                right = x;
            }
            else
            {
                nZeros--;
                nOnes++;
            }

            if (nZeros < nOnes)
            {
                int f = nOnes - nZeros - 1;
                auto l1 = lower_bound(st.begin(), st.end(), left - f);
                if (l1 != st.end() && l1->F <= left && l1->S >= right)
                {
                    int df = l1->S - l1->F + 1;
                    if (df <= (right - left + 1) + f)
                    {
                    }
                }
            }
        }
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