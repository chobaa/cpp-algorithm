#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, fuel, sy, sx, state, next_idx, pass_cnt;

int map[21][21];
vector<pair<int, int>> ps;
vector<pair<int, int>> goal;
int cnt[21][21];
vector<bool> check;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dijkstra()
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    cnt[sy][sx] = 0;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (map[ny][nx] == 0 && cnt[ny][nx] == -1)
            {
                cnt[ny][nx] = cnt[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> fuel;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> sy >> sx;
    sy -= 1;
    sx -= 1;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ps.push_back({a - 1, b - 1});
        goal.push_back({c - 1, d - 1});
        check.push_back(false);
    }
    state = 0;
    bool fail = false;
    int total = m * 2;
    while (total--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cnt[i][j] = -1;
            }
        }
        dijkstra();
        int y1, x1;
        int next = 987654321;
        if (state == 0)
        {
            next_idx = -1;
            for (int i = 0; i < m; i++)
            {
                if (check[i])
                    continue;
                y1 = ps[i].first;
                x1 = ps[i].second;
                if (next > cnt[y1][x1] && cnt[y1][x1] != -1)
                {
                    next = cnt[y1][x1];
                    next_idx = i;
                }
            }
            if (next_idx == -1)
            {
                fail = true;
                break;
            }
            sy = ps[next_idx].first;
            sx = ps[next_idx].second;
            check[next_idx] = true;
            fuel -= next;
            state = 1;
        }
        else
        {
            y1 = goal[next_idx].first;
            x1 = goal[next_idx].second;
            next = cnt[y1][x1];
            if (next == -1)
            {
                fail = true;
                break;
            }
            fuel -= next;
            if (fuel < 0)
            {
                fail = true;
                break;
            }
            fuel += next * 2;
            sy = y1;
            sx = x1;
            state = 0;
        }
    }
    if (fail)
        cout << -1;
    else
        cout << fuel;
}