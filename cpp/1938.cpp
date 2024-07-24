#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

char map[51][51];

int sy, sx, fy, fx, ss, fs; // ss = 0이면 가로로 있는 상태, ss = 1이면 세로로 있는 상태

int dy[4] = {2, 0, -2, 0};
int dx[4] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int ny, nx;
        for (int i = 0; i < 4; i++)
        {
            if (ss == 0)
            {
                ny = cy + dy[i];
                nx = cx + dx[i];
            }
            else
            {
                ny = cy + dx[i];
                nx = cx + dy[i];
            }
            if (ny < 0 || ny > n || nx < 0 || nx > n)
                continue;
            if (ss == 0 && map[ny][nx] == 0)
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'B')
            {
                if (j - 1 >= 0 && map[i][j - 1] == 'B')
                {
                    sy = i;
                    sx = j;
                    ss = 0
                }
                if (i - 1 >= 0 && map[i - 1][j] == 'B')
                {
                    sy = i;
                    sx = j;
                    ss = 1;
                }
            }
            if (map[i][j] == 'E')
            {
                if (j - 1 >= 0 && map[i][j - 1] == 'E')
                {
                    fy = i;
                    fx = j;
                    fs = 0;
                }
                if (i - 1 >= 0 && map[i - 1][j] == 'E')
                {
                    fy = i;
                    fx = j;
                    fs = 1;
                }
            }
        }
    }
    bfs();
}