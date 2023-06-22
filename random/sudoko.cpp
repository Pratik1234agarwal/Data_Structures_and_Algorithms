#include <bits/stdc++.h>
using namespace std;
#include <chrono>

class Solution
{
public:
    using pii = pair<int, int>;
    bool isValid(pii s, vector<vector<char>> &board)
    {
        int x = s.first;
        int y = s.second;
        int r = board[x][y];

        int matches = 0;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][y] == board[x][y])
                matches++;
            if (board[x][i] == board[x][y])
                matches++;
        }

        if (matches != 2)
            return false;

        // Check for the grid;
        int rNum = x / 3;
        int cNum = y / 3;
        matches = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + rNum * 3][j + cNum * 3] == board[x][y])
                {
                    matches++;
                }
            }
        }

        if (matches > 1)
        {
            return false;
        }

        return true;
    }
    bool solve(int c, vector<vector<char>> &board, vector<pair<int, int>> fills, int dp[][][])
    {

        // Condition that the sudoko is filled completey and correctly
        if (c == fills.size())
        {
            return true;
        }

        int x = fills[c].first, y = fills[c].second;

        for (int i = 1; i <= 9; i++)
        {
            board[x][y] = '0' + i; // Fix the int to char conversion
            if (isValid({x, y}, board))
            {
                // cout<<"Solve : "<<c+1<<endl;

                if (solve(c + 1, board, fills))
                {
                    return true;
                }
            }

            // backtrack
        }

        board[x][y] = '.';

        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<pii> fills;
        int c = 0;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    fills.push_back({i, j});
                }
            }
        }

        bool ff = solve(0, board, fills);
        cout << ff << endl;
    }
};

int main()
{
    Solution solution;
    int dp[9][9][10] = {-1};

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '.', '.', '.', '.', '.'},
        {'.', '9', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '.'},
        {'.', '6', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '9'}};

    auto start = chrono::high_resolution_clock::now();

    solution.solveSudoku(board);

    // Print the solved board
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}