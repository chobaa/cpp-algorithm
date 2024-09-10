#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int board[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
int cnt = 0;

void fill_block(int i, int j, int target, bool a)
{
    row[j][target] = a;
    col[i][target] = a;
    square[(i / 3) * 3 + j / 3][target] = a;
}

void dfs(int cnt)
{
    if (cnt == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    int y = cnt / 9;
    int x = cnt % 9;
    if (board[y][x] == 0)
    {
        for (int t = 1; t <= 9; t++)
        {
            if (!col[y][t] && !row[x][t] && !square[(y / 3) * 3 + x / 3][t])
            {
                fill_block(y, x, t, true);
                board[y][x] = t;
                dfs(cnt + 1);
                board[y][x] = 0;
                fill_block(y, x, t, false);
            }
        }
    }
    else
        dfs(cnt + 1);
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = temp[j] - '0';
            if (temp[j] != '0')
            {
                cnt++;
                fill_block(i, j, board[i][j], true);
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dfs(0);
        }
    }
}