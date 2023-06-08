#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> arr;

using lli = long long int;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

int countRooms = 0;

#define F first
#define S second

const int INF = 1e9;
const char WALL = '#';
const char FLOOR = '.';

vector<ii> spaces;

vvi vis;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// typedef pair<int,int> ii;

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == WALL)
        return false;
    return true;
}

vector<ii> neighbours(ii cur)
{
    vector<ii> nn;

    for (int i = 0; i < 4; i++)
    {
        int newX = cur.F + dx[i];
        int newY = cur.S + dy[i];
        if (isValid(newX, newY))
        {
            nn.push_back(make_pair(newX, newY));
        }
    }

    return nn;
}

void bfs(ii st)
{

    queue<ii> q;
    q.push(st);
    vis[st.F][st.S] = 1;

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
            }
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
            if (arr[i][j] == FLOOR)
            {
                spaces.push_back({i, j});
            }
        }
    }

    vis = vvi(n, vi(m, 0));

    for (auto v : spaces)
    {
        if (!vis[v.F][v.S])
        {
            countRooms++;
            bfs(v);
        }
    }

    cout << countRooms << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();
}