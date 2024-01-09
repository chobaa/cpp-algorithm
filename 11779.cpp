#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, city_start, city_end;

vector<pair<int, int>> route[1001];

int dist[1001];
int before[1001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, city_start});
    dist[city_start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int city = pq.top().second;
        pq.pop();
        if (cost > dist[city])
        {
            continue;
        }
        for (int i = 0; i < route[city].size(); i++)
        {
            int ncost = route[city][i].first;
            int ncity = route[city][i].second;
            if (dist[ncity] > cost + ncost)
            {
                dist[ncity] = cost + ncost;
                pq.push({-dist[ncity], ncity});
                before[ncity] = city;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        route[start].push_back({cost, end});
    }
    cin >> city_start >> city_end;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 30000000;
    }

    dijkstra();

    vector<int> road;
    int val = city_end;
    while (val)
    {
        road.push_back(val);
        val = before[val];
    }

    cout << dist[city_end] << "\n";
    cout << road.size() << "\n";
    reverse(road.begin(), road.end());
    for (int i = 0; i < road.size(); i++)
    {
        cout << road[i] << " ";
    }
}