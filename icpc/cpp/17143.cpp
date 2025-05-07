#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int r, c, m;
int map[101][101];
int next_map[101][101];
int shark_info[10001][3];
int fisher = 1;
int answer = 0;

pair<int, int> calculate_dir(int y, int x, int idx)
{
    int cs = shark_info[idx][0];
    int cd = shark_info[idx][1];
    while (cs > 0)
    {
        switch (cd)
        {
        case 1:
            if (y - cs >= 1)
            {
                y -= cs;
                cs = 0;
            }
            else
            {
                cs -= y - 1;
                y = 1;
                cd = 2;
            }
            break;
        case 2:
            if (y + cs <= r)
            {
                y += cs;
                cs = 0;
            }
            else
            {
                cs -= r - y;
                y = r;
                cd = 1;
            }
            break;
        case 3:
            if (x + cs <= c)
            {
                x += cs;
                cs = 0;
            }
            else
            {
                cs -= c - x;
                x = c;
                cd = 4;
            }
            break;
        case 4:
            if (x - cs >= 1)
            {
                x -= cs;
                cs = 0;
            }
            else
            {
                cs -= x - 1;
                x = 1;
                cd = 3;
            }
            break;
        }
    }
    shark_info[idx][1] = cd;
    pair<int, int> temp = {y, x};
    return temp;
}

int main()
{
    cin >> r >> c >> m;
    for (int i = 1; i <= m; i++)
    {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        map[y][x] = i;
        shark_info[i][0] = s;
        shark_info[i][1] = d;
        shark_info[i][2] = z;
    }
    while (fisher <= c)
    {
        for (int i = 1; i <= r; i++)
        {
            if (map[i][fisher] != 0)
            {
                answer += shark_info[map[i][fisher]][2];
                map[i][fisher] = 0;
                break;
            }
        }
        memset(next_map, 0, sizeof(next_map));
        queue<pair<pair<int, int>, pair<int, int>>> cmpq;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (map[i][j] != 0)
                {
                    int cur = map[i][j];
                    pair<int, int> temp = calculate_dir(i, j, cur);
                    if (next_map[temp.first][temp.second] != 0)
                    {
                        int size1 = shark_info[cur][2];
                        int size2 = shark_info[next_map[temp.first][temp.second]][2];
                        if (size1 > size2)
                        {
                            next_map[temp.first][temp.second] = cur;
                        }
                    }
                    else
                    {
                        next_map[temp.first][temp.second] = cur;
                    }
                }
            }
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                map[i][j] = next_map[i][j];
            }
        }
        fisher++;
    }
    cout << answer << "\n";
}