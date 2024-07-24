#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100

using namespace std;

int n, m, r;

int map[101];
vector<pair<int, int>> route[101];
int dist[101];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < route[cur].size(); i++)
        {
            int next = route[cur][i].first;
            int ncost = route[cur][i].second;
            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push({-(cost + ncost), next});
            }
        }
    }
}

int main()
{
    int answer = 0;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < r; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        route[from].push_back({to, weight});
        route[to].push_back({from, weight});
    }
    for (int i = 1; i <= n; i++)
        dist[i] = MAX;
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        int total = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] <= m)
                total += map[j];
            dist[j] = MAX;
        }
        if (answer < total)
            answer = total;
    }
    cout << answer;
}