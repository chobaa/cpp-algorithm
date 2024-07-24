#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n, k, l, answer = 0, y, x, idx = 0, cd = 0;
int board[101][101];
vector<pair<int, char>> order;
queue<pair<int, int>> q;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool move(int direction)
{
    answer++;
    y += dy[direction];
    x += dx[direction];
    if (y < 0 || y >= n || x < 0 || x >= n)
        return false;
    if (board[y][x] == 2)
        return false;
    if (board[y][x] == 0)
    {
        q.push({y, x});
        board[q.front().first][q.front().second] = 0;
        q.pop();
    }
    if (board[y][x] == 1)
        q.push({y, x});
    board[y][x] = 2;
    if (answer == order[idx].first)
    {
        if (order[idx].second == 'D')
            cd = (cd + 1) % 4;
        else
            cd = (cd + 3) % 4;
        idx++;
        if (idx == l)
            idx = 0;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        order.push_back({a, b});
    }
    q.push({0, 0});
    while (1)
    {
        if (!move(cd))
        {
            cout << answer << "\n";
            break;
        }
    }
}