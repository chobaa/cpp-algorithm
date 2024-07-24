#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;

int map[501][501];
int dp[501][501];
bool visited[501][501];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int result = 0;

int dfs(int y, int x)
{
    if (y == m - 1 && x == n - 1)
        return 1;
    if (visited[y][x])
    {
        return dp[y][x];
    }
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
        if (map[y][x] > map[ny][nx])
        {
            dp[y][x] += dfs(ny, nx);
        }
    }
    return dp[y][x];
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            dp[i][j] = 0;
        }
    }

    cout << dfs(0, 0);
}