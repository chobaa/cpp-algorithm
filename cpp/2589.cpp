#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, answer = 0;

char map[51][51];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs(int y, int x)
{
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;
    q.push({y, x});
    cnt[y][x] = 0;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cnt[cy][cx] > answer)
            answer = cnt[cy][cx];
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == 'L' && cnt[ny][nx] == -1)
            {
                q.push({ny, nx});
                cnt[ny][nx] = cnt[cy][cx] + 1;
            }
        }
    }
}

int main()
{
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
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'L')
            {
                bfs(i, j);
            }
        }
    }
    cout << answer;
}