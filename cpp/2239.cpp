#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int board[9][9];
int possible[10][9][9];
int cnt = 0;

void fill_block(int i, int j, int target)
{
    for (int t = 0; t < 9; t++)
    {
        possible[target][t][j] = 1;
        possible[target][i][t] = 1;
    }
    i -= i % 3;
    j -= j % 3;
    for (int t = i; t < i + 3; t++)
    {
        for (int f = j; f < j + 3; f++)
        {
            possible[target][t][f] = 1;
        }
    }
}

// possible을 다 걸러뒀고 dfs를 해서 백트래킹을 할려고 했는데, 이렇게 하면 다른 변수땜에 오염됨.
// 각각의 row, col, square를 만들어서 하는 이유를 알거같음. 내일 수정 ㄱ
void dfs(int y, int x)
{
    if (board[y][x] == 0)
    {
        for (int t = 1; t <= 9; t++)
        {
            if (possible[t][y][x] == 0)
            {
            }
        }
    }
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
                fill_block(i, j, board[i][j]);
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dfs(i, j);
        }
    }
}