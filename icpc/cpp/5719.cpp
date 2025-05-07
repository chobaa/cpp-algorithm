#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

vector<vector<int>> parent;
vector<vector<pair<int, int>>> road;
bool check[501][501];

int n, m, s, e;

int dijkstra()
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cost > dist[cur])
            continue;
        for (auto a : road[cur])
        {
            int ncost = a.second;
            int next = a.first;
            if (check[cur][next])
                continue;
            if (dist[next] > cost + ncost)
            {
                parent[next].clear();
                parent[next].push_back(cur);
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
            if (dist[next] == cost + ncost)
            {
                parent[next].push_back(cur);
            }
        }
    }
    return dist[e] == INF ? -1 : dist[e];
}

void remove_way(int cur)
{
    for (auto a : parent[cur])
    {
        for (int i = 0; i < road[a].size(); i++)
        {
            if (road[a][i].first == cur && !check[a][cur])
            {
                check[a][cur] = true;
                remove_way(a);
                break;
            }
        }
    }
}

int main()
{
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        memset(check, false, sizeof(check));
        road.clear();
        parent.clear();

        road.resize(n);
        parent.resize(n);

        cin >> s >> e;
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            road[u].push_back({v, p});
        }
        dijkstra();
        remove_way(e);
        cout << dijkstra() << "\n";
    }
}