#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int n, answer = 0;

int dp[501][501];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int y, int x)
{
    if (dp[y][x] != 0)
        return dp[y][x];
    dp[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (map[y][x] < map[ny][nx])
        {
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        }
    }
    return dp[y][x];
}

int main()
{
    cin >> n;
    map.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer = max(answer, dfs(i, j));
        }
    }
    cout << answer;
}