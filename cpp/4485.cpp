#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 99999999

int cave[126][126];
int dist[126][126];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int n;

void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-cave[0][0], {0, 0}});
    dist[0][0] = cave[0][0];
    while (!pq.empty())
    {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > dist[y][x])
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            int ncost = cave[ny][nx];
            if (dist[ny][nx] > cost + ncost)
            {
                dist[ny][nx] = cost + ncost;
                pq.push({-dist[ny][nx], {ny, nx}});
            }
        }
    }
}

int main()
{
    for (int t = 1; t >= 0; t++)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cave[i][j];
                dist[i][j] = MAX;
            }
        }
        dijkstra();
        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
    }
}