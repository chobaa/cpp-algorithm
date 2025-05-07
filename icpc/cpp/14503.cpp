#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cy, cx, d;
int stage[51][51];

int dy[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int dx[8] = {0, -1, 0, 1, 0, -1, 0, 1};

int cleaning()
{
    int answer = 0;
    while (1)
    {
        bool checked = false;
        if (stage[cy][cx] == 0)
        {
            answer++;
            stage[cy][cx] = 2;
        }
        for (int i = 1; i <= 4; i++)
        {
            int ny = cy + dy[d + i];
            int nx = cx + dx[d + i];
            if (stage[ny][nx] == 0)
            {
                cy = ny;
                cx = nx;
                d = (d + i) % 4;
                checked = true;
                break;
            }
        }
        if (!checked)
        {
            cy -= dy[d];
            cx -= dx[d];
            if (stage[cy][cx] == 1)
                return answer;
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> cy >> cx >> d;
    if (d == 1)
        d = 3;
    else if (d == 3)
        d = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> stage[i][j];
        }
    }
    cout << cleaning();
}