#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<bool>> check;

int bfs(int y, int x, int cur_map)
{
    queue<pair<int, int>> q;
    vector<vector<int>> count(n, vector<int>(n, 0));
    count[y][x] = 1;
    q.push({y, x});
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;
            if (count[next_y][next_x] == 0 && map[next_y][next_x] != cur_map)
            {
                if (map[next_y][next_x] != 0)
                    return count[cur_y][cur_x];
                else
                {
                    count[next_y][next_x] = count[cur_y][cur_x] + 1;
                    q.push({next_y, next_x});
                }
            }
        }
    }
    return 10001;
}

void find_same_land(int y, int x, int idx)
{
    queue<pair<int, int>> q;
    map[y][x] = idx;
    q.push({y, x});
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;
            if (!check[next_y][next_x] && map[next_y][next_x] == 1)
            {
                check[next_y][next_x] = true;
                map[next_y][next_x] = idx;
                q.push({next_y, next_x});
            }
        }
    }
}

int main()
{
    cin >> n;
    map.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    check.resize(n, vector<bool>(n, 0));
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !check[i][j])
            {
                check[i][j] = true;
                find_same_land(i, j, idx++);
            }
        }
    }
    int answer = 10001;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] < 1)
                continue;
            for (int t = 0; t < 4; t++)
            {
                int next_x = x + dx[t];
                int next_y = y + dy[t];
                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                    continue;
                if (map[next_y][next_x] == 0)
                    answer = min(answer, bfs(next_y, next_x, map[y][x]));
            }
        }
    }

    cout << answer;
}