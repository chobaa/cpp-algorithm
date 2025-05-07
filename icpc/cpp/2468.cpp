#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int map[101][101];
int visited[101][101];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(int cy, int cx)
{
    visited[cy][cx] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (!visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> n;
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            top = max(map[i][j], top);
        }
    }
    int answer = 0;
    for (int t = 0; t <= top; t++)
    {
        // 해당하는 지역 지우기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] <= t)
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    dfs(i, j);
                    total++;
                }
            }
        }
        answer = max(answer, total);
    }
    cout << answer;
}