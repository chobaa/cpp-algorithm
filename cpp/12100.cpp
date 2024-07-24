#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long answer;

vector<vector<long long>> board;

long long get_max(vector<vector<long long>> board)
{
    long long temp = 0;
    for (long long i = 0; i < board.size(); i++)
    {
        for (long long j = 0; j < board[i].size(); j++)
        {
            temp = max(temp, board[i][j]);
        }
    }
    return temp;
}

vector<vector<long long>> move_left(vector<vector<long long>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[i][k] == board[i][k + 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else
                    break;
            }
        }
    }
    return board;
}

vector<vector<long long>> move_right(vector<vector<long long>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[i][k] == board[i][k - 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else
                    break;
            }
        }
    }
    return board;
}

vector<vector<long long>> move_up(vector<vector<long long>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = i - 1; k >= 0; k--)
            {
                if (board[k][j] == board[k + 1][j] && !check[k][j])
                {
                    board[k][j] *= 2;
                    board[k + 1][j] = 0;
                    check[k][j] = true;
                    break;
                }
                else if (board[k][j] == 0)
                {
                    board[k][j] = board[k + 1][j];
                    board[k + 1][j] = 0;
                }
                else
                    break;
            }
        }
    }
    return board;
}

vector<vector<long long>> move_down(vector<vector<long long>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = i + 1; k < n; k++)
            {
                if (board[k][j] == board[k - 1][j] && !check[k][j])
                {
                    board[k][j] *= 2;
                    board[k - 1][j] = 0;
                    check[k][j] = true;
                    break;
                }
                else if (board[k][j] == 0)
                {
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = 0;
                }
                else
                    break;
            }
        }
    }
    return board;
}

void move(int trial, vector<vector<long long>> board)
{
    answer = max(answer, get_max(board));

    if (trial == 5)
        return;

    move(trial + 1, move_left(board));
    move(trial + 1, move_right(board));
    move(trial + 1, move_up(board));
    move(trial + 1, move_down(board));
}

int main()
{
    cin >> n;
    board.resize(21, vector<long long>(21));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    move(0, board);
    cout << answer;
}