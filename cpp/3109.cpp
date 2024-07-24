#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, answer;
char map[10001][501];
int cnt[10001][501];

int dy[3] = {-1, 0, 1};

bool dfs(int y, int x)
{
    if (x == m - 1)
    {
        answer++;
        return true;
    }
    map[y][x] = 'x';
    for (int i = 0; i < 3; i++)
    {
        int ny = y + dy[i];
        if (ny < 0 || ny >= n)
            continue;
        if (map[ny][x + 1] == '.')
        {
            if (dfs(ny, x + 1))
                return true;
        }
    }
    return false;
}

int main()
{
    answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 0);
    }
    cout << answer << "\n";
}