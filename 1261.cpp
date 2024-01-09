#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m;

#define INF 987654321

int map[101][101];
int cnt[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    cnt[0][0] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if (cnt[y][x] < cost)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ncost = 0;
            if (map[ny][nx] == 1)
                ncost = 1;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (cnt[ny][nx] > cost + ncost)
            {
                cnt[ny][nx] = cost + ncost;
                pq.push({-cnt[ny][nx], {ny, nx}});
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = str[j] - '0';
            cnt[i][j] = INF;
        }
    }
    bfs();
    cout << cnt[n - 1][m - 1];
}