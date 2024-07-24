#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int dist[300001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            int ncost = cost + 1;
            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k >> x;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 987654321;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dijkstra();
    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
        if (i != x && dist[i] == k)
            answer.push_back(i);
    }
    if (answer.empty())
        cout << -1 << "\n";
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << "\n";
        }
    }
}