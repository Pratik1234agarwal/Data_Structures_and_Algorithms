#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        arr.push_back(r);
    }
    multiset<int> st;
    for (int i = 0; i < k - 1; i++)
    {
        st.insert(arr[i]);
    }
    int m = 0;
    if (!st.empty())
    {
        m = *(st.rbegin());
    }
    for (int i = k - 1; i < n; i++)
    {
        if (i != k - 1)
        {
            st.erase(st.find(arr[i - k]));
        }
        st.insert(arr[i]);
        cout << *(st.rbegin()) << " ";
    }
    cout << endl;
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