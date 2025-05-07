#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int n, k;
int dist[100001];

void dijkstra()
{
    dist[n] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, n});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] > cost)
            continue;
        int next = cur - 1;
        int ncost = 1;
        if (next >= 0 && dist[next] > cost + ncost)
        {
            dist[next] = cost + ncost;
            pq.push({-dist[next], next});
        }
        next = cur + 1;
        if (next <= 100000 && dist[next] > cost + ncost)
        {
            dist[next] = cost + ncost;
            pq.push({-dist[next], next});
        }
        next = cur * 2;
        ncost = 0;
        if (next <= 100000 && dist[next] > cost + ncost)
        {
            dist[next] = cost + ncost;
            pq.push({-dist[next], next});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < 100001; i++)
    {
        dist[i] = INF;
    }
    dijkstra();
    cout << dist[k];
}