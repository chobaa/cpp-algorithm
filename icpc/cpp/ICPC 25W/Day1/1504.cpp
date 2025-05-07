#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int n, e;
long long answer1,answer2;
// answer1 = 1 ~ v1 ~ v2 ~ n, answer2 = 1 ~ v2 ~ v1 ~ n
vector<pair<int, int>> graph[801];
int dist[801];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] != cost)
            continue;
        for (auto temp : graph[cur])
        {
            int next = temp.first;
            int ncost = temp.second;
            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }
    int v1, v2;
    cin >> v1 >> v2;
    answer1 = answer2 = 0;
    // 시작점에서 v1, v2까지의 cost
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dijkstra(1);
    answer1 += dist[v1];
    answer2 += dist[v2];
    // v1에서 v2까지의 cost
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dijkstra(v1);
    answer1 += dist[v2];
    answer2 += dist[v2];
    // n에서 v1,v2까지의 cost
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dijkstra(n);
    answer1 += dist[v2];
    answer2 += dist[v1];
    answer1 = min(answer1, answer2);
    if (answer1 >= INF)
        cout << -1;
    else
        cout << answer1;
}