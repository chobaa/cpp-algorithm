#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[9][9];
int temp[9][9];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pair<int, int>> virus;

int answer = 0;

int n, m;

void bfs()
{
    int map2[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map2[i][j] = temp[i][j];
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
    {
        q.push({virus[i].first, virus[i].second});
    }
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
                continue;
            if (map2[next_y][next_x] == 0)
            {
                map2[next_y][next_x] = 2;
                q.push({next_y, next_x});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map2[i][j] == 0)
                count++;
        }
    }

    answer = max(answer, count);
}

void wall(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                temp[i][j] = 1;
                wall(cnt + 1);
                temp[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    vector<pair<int, int>> possible;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        temp[i][j] = map[i][j];
                    }
                }
                temp[i][j] = 1;
                wall(1);
                temp[i][j] = 0;
            }
        }
    }

    cout << answer;
}