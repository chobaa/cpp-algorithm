#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[8][8];
int backup[8][8][8];
int n, m;
int answer = 987654321;
int cnt[6] = {0, 4, 2, 4, 4, 1};
vector<pair<int, int>> cctv;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void movemap(int idx, int dir)
{
    dir = dir % 4;
    int cy = cctv[idx].first;
    int cx = cctv[idx].second;
    cy += dy[dir];
    cx += dx[dir];
    while (cy >= 0 && cy < n && cx >= 0 && cx < m)
    {
        if (map[cy][cx] == 6)
            break;
        if (map[cy][cx] == 0)
        {
            map[cy][cx] = -1;
        }
        cy += dy[dir];
        cx += dx[dir];
    }
}

void clearmap(int idx)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = backup[idx][i][j];
        }
    }
}

void sketch_map(int idx)
{
    if (idx == cctv.size())
    {
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 0)
                    cur++;
            }
        }
        if (cur < answer)
            answer = cur;
        return;
    }
    int cctype = map[cctv[idx].first][cctv[idx].second];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            backup[idx][i][j] = map[i][j];
        }
    }
    for (int i = 0; i < cnt[cctype]; i++)
    {
        switch (cctype)
        {
        case 1:
            movemap(idx, i);
            sketch_map(idx + 1);
            clearmap(idx);
            break;
        case 2:
            movemap(idx, i);
            movemap(idx, i + 2);
            sketch_map(idx + 1);
            clearmap(idx);
            break;
        case 3:
            movemap(idx, i);
            movemap(idx, i + 1);
            sketch_map(idx + 1);
            clearmap(idx);
            break;
        case 4:
            movemap(idx, i);
            movemap(idx, i + 1);
            movemap(idx, i + 2);
            sketch_map(idx + 1);
            clearmap(idx);
            break;
        case 5:
            movemap(idx, i);
            movemap(idx, i + 1);
            movemap(idx, i + 2);
            movemap(idx, i + 3);
            sketch_map(idx + 1);
            clearmap(idx);
            break;
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
            if (map[i][j] == 6 || map[i][j] == 0)
                continue;
            else
            {
                cctv.push_back({i, j});
            }
        }
    }
    sketch_map(0);

    cout << answer;
}