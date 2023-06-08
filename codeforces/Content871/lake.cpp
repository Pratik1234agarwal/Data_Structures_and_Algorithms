#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;
using sti = set<int>;
using mpii = map<int, int>;

#define endl '\n'
#define F first
#define S second

vector<vi> vis;
lli sum = 0;

int dx[] = {1, -1, 0, 0}; // R L D U
int dy[] = {0, 0, 1, -1};

vector<vi> arr;
int n, m;

queue<ii> q;

int isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (arr[x][y] == 0)
        return 0;
    return 1;
}

int explore(ii cur)
{
    sum = 0;
    vis[cur.F][cur.S] = 1;
    sum += arr[cur.F][cur.S];
    q.push(cur);

    while (!q.empty())
    {
        ii current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nX = current.F + dx[i];
            int nY = current.S + dy[i];
            if (isValid(nX, nY) && !vis[nX][nY])
            {
                vis[nX][nY] = 1;
                q.push({nX, nY});
                sum += arr[nX][nY];
            }
        }
    }

    return sum;
}

void solve()
{
    cin >> n >> m;
    arr.resize(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int r;
            cin >> r;
            arr[i][j] = r;
        }
    }

    vis.assign(n, vi(m, 0));

    while (!q.empty())
        q.pop();

    int mEle = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j) && !vis[i][j])
            {
                int s = explore({i, j});
                mEle = max(mEle, s);
            }
        }
    }

    cout << mEle << endl;
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