#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> map;
bool check[101][101];
int n, m, total = 0, cnt, attempt = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (!check[ny][nx])
            {
                check[ny][nx] = true;
                if (map[ny][nx] == 1)
                {
                    cnt++;
                    map[ny][nx] = 0;
                }
                else
                    q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                total++;
        }
    }
    while (1)
    {
        attempt++;
        cnt = 0;
        memset(check, false, sizeof(check));
        for (int i = 0; i < n; i++)
        {
            if (!check[i][0])
            {
                bfs(i, 0);
            }
            if (!check[i][m - 1])
            {
                bfs(i, m - 1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (!check[0][i])
            {
                bfs(0, i);
            }
            if (!check[i][m - 1])
            {
                bfs(n - 1, i);
            }
        }
        if (total - cnt == 0)
        {
            if (cnt == 0)
                attempt = 0;
            cout << attempt << "\n";
            cout << total << "\n";
            break;
        }
        total -= cnt;
    }
}