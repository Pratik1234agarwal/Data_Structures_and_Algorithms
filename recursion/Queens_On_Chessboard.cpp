#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using ll = long long int;
using pll = pair<ll, ll>;
using mpii = map<int, int>;
using mpll = map<ll, ll>;

#define F first
#define S second
#define endl '\n'

const int N = 8;
char arr[N][N];
int c;

vi rBlock, cBlock;
vector<pii> locations;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

bool isValid(int i, int j)
{
    char ch = arr[i][j];
    // Check weather it is not a .
    if (ch != '.')
        return false;
    // Check if the queens interact
    if (rBlock[i] || cBlock[j])
        return false;
    for (auto it : locations)
    {
        int x = it.first;
        int y = it.second;

        // Check for the diagonal relation
        for (int i = 0; i < 4; i++)
        {
            int nX = dx[i];
            int nY = dy[i];
            while (nX + x >= 0 && nX + x < N && nY + y >= 0 && nY + y < N)
            {
                x = x + nX;
                y = y + nY;

                if (x == i && y == j)
                    return false;
            }
        }
    }

    return true;
}

void rec(int level)
{
    if (level == 9)
    {
        c++;
    }
    else
    {
        // Navigate the entire board, find where you can place the elements.
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char ch = arr[i][j];

                if (isValid(i, j))
                {
                    // Place Queen at index (i,j)
                    arr[i][j] = 'q';
                    rBlock[i] = 1;
                    cBlock[j] = 1;
                    locations.push_back({i, j});
                    rec(level + 1);
                    locations.pop_back();
                    cBlock[j] = 0;
                    rBlock[i] = 0;
                    arr[i][j] = '.';
                }
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    c = 0;
    rBlock.assign(N, 0);
    cBlock.assign(N, 0);

    rec(1);

    cout << c << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}