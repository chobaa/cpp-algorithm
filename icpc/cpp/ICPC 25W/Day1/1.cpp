#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 20000000001

using namespace std;

int n, m, x, y;
vector<pair<int, int>> graph[100001];
long long dist[100001][3];

void dijkstra()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,x});
    dist[x][0] = 0;
    dist[x][2] = 1;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur][0] > cost)
            continue;
        for (auto temp : graph[cur])
        {
            int next = temp.first;
            int ncost = temp.second;
            if (dist[next][0] > cost + ncost)
            {
                dist[next][0] = cost + ncost;
                dist[next][1] = dist[cur][1] + 1;
                dist[next][2] = dist[cur][2] % 1000000009;
                pq.push({-dist[next][0],next});
            }
            else if (dist[next][0] == cost + ncost)
            {
                if (dist[next][1] == dist[cur][1] + 1)
                {
                    dist[next][2] = (dist[next][2] + dist[cur][2]) % 1000000009;
                }
                else if (dist[next][1] > dist[cur][1] + 1)
                {
                    dist[next][0] = cost + ncost;
                    dist[next][1] = dist[cur][1] + 1;
                    dist[next][2] = (dist[cur][2]) % 1000000009;
                    pq.push({-dist[next][0],next});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    for (int i = 0; i < 100001; i++)
    {
        dist[i][0] = INF;
    }
    dijkstra();
    if (dist[y][0] == INF)
        cout << -1;
    else
    {
        cout << dist[y][0] << "\n";
        cout << dist[y][1] << "\n";
        cout << dist[y][2] << "\n";
    }
}