#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char map[1501][1501];
bool check[1501][1501];
int n, m, by, bx, answer = 0;
queue<pair<int, int>> waterq;
queue<pair<int, int>> swanq;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void melting()
{
    int size = waterq.size();
    while (size--)
    {
        int cy = waterq.front().first;
        int cx = waterq.front().second;
        waterq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == 'X')
            {
                waterq.push({ny, nx});
                map[ny][nx] = '.';
            }
        }
    }
}

bool isMeet()
{
    queue<pair<int, int>> q;
    while (!swanq.empty())
    {
        int cy = swanq.front().first;
        int cx = swanq.front().second;
        swanq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (!check[ny][nx])
            {
                if (map[ny][nx] == 'X')
                    q.push({ny, nx});
                else if (map[ny][nx] == 'L' && (by != ny || bx != nx))
                {
                    by = -1;
                    bx = -1;
                    return true;
                }
                else
                    swanq.push({ny, nx});
                check[ny][nx] = true;
            }
        }
    }
    swanq = q;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '.')
                waterq.push({i, j});
            if (map[i][j] == 'L')
            {
                by = i;
                bx = j;
                waterq.push({i, j});
            }
        }
    }
    swanq.push({by, bx});
    while (!isMeet())
    {
        answer++;
        melting();
    }
    if (by != -1)
        answer = 0;
    cout << answer;
}