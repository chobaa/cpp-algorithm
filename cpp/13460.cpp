#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

int n, m;

char map[11][11];

int red_x, red_y, blue_x, blue_y;

int next_dir[4][4] = {{1, 0, 1, 0},
                      {0, 1, 0, 1},
                      {-1, 0, -1, 0},
                      {0, -1, 0, -1}};

int bfs()
{
    queue<tuple<int, int, int, int, int>> q;
    q.push({red_y, red_x, blue_y, blue_x, 0});
    while (!q.empty())
    {
        int ry = get<0>(q.front());
        int rx = get<1>(q.front());
        int by = get<2>(q.front());
        int bx = get<3>(q.front());
        int cnt = get<4>(q.front());
        q.pop();
        if (cnt > 10)
            return -1;
        for (int direction = 0; direction < 4; direction++)
        {
            bool move_r = true, move_b = true, pass_r = false, pass_b = false;
            int next[4] = {ry, rx, by, bx};
            while (move_r || move_b)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (i <= 1 && move_r)
                        next[i] += next_dir[direction][i];
                    else if (i > 1 && move_b)
                        next[i] += next_dir[direction][i];
                }
                if (move_r)
                {
                    if (map[next[0]][next[1]] == 'O')
                    {
                        pass_r = true;
                        move_r = false;
                    }
                    else if (map[next[0]][next[1]] == '#')
                    {
                        next[0] -= next_dir[direction][0];
                        next[1] -= next_dir[direction][1];
                        move_r = false;
                    }
                }
                if (move_b)
                {
                    if (map[next[2]][next[3]] == 'O')
                    {
                        pass_b = true;
                        move_b = false;
                    }
                    else if (map[next[2]][next[3]] == '#')
                    {
                        next[2] -= next_dir[direction][2];
                        next[3] -= next_dir[direction][3];
                        move_b = false;
                    }
                }
            }
            if (pass_r && !pass_b)
                return cnt + 1;
            else if (pass_b)
                continue;
            if (next[0] == next[2] && next[1] == next[3])
            {
                if (direction % 2 == 0)
                {
                    if (abs(next[0] - ry) > abs(next[2] - by))
                        next[0] -= next_dir[direction][0];
                    else
                        next[2] -= next_dir[direction][2];
                }
                else
                {
                    if (abs(next[1] - rx) > abs(next[3] - bx))
                        next[1] -= next_dir[direction][1];
                    else
                        next[3] -= next_dir[direction][3];
                }
            }
            if (next[0] != ry || next[1] != rx || next[2] != by || next[3] != bx)
            {
                q.push({next[0], next[1], next[2], next[3], cnt + 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
            {
                red_y = i;
                red_x = j;
            }
            else if (map[i][j] == 'B')
            {
                blue_y = i;
                blue_x = j;
            }
        }
    }
    int answer = -1;
    answer = bfs();
    if (answer > 10)
        answer = -1;
    cout << answer;
}