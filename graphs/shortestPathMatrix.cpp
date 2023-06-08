#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> arr;

using lli = long long int;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define F first
#define S second

const int INF = 1e9;
const char WALL = 'w';
// typedef pair<int,int> ii;

vector<ii> neighbours(ii cur)
{
    vector<ii> nn;
    if (cur.F != 0 && arr[cur.F - 1][cur.S] != WALL)
    {
        nn.push_back({cur.F - 1, cur.S});
    }
    if (cur.F != n - 1 && arr[cur.F + 1][cur.S] != WALL)
    {
        nn.push_back({cur.F + 1, cur.S});
    }

    if (cur.S != 0 && arr[cur.F][cur.S - 1] != WALL)
    {
        nn.push_back({cur.F, cur.S - 1});
    }
    if (cur.S != n - 1 && arr[cur.F][cur.S + 1] != WALL)
    {
        nn.push_back({cur.F, cur.S + 1});
    }

    return nn;
}

vvi vis,
    dis;
void bfs(ii st)
{
    vis = vvi(n, vi(m, 0));
    dis = vvi(n, vi(m, INF));

    queue<ii> q;
    q.push(st);
    vis[st.F][st.S] = 1;
    dis[st.F][st.S] = 0;

    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();

        for (auto v : neighbours(cur))
        {
            if (!vis[v.F][v.S])
            {
                q.push(v);
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[cur.F][cur.S] + 1;
            }
        }

        if (!vis[cur.F][cur.S])
        {
            q.push(cur);
        }
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    ii st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 's')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'f')
            {
                en = {i, j};
            }
        }
    }

    bfs(st);
    if (vis[en.F][en.S])
    {
        cout << "Can Reach" << endl;
        cout << dis[en.F][en.S] << endl;
    }
    else
    {
        cout << "Can't Reach" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}