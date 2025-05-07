#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;

vector<pair<int, int>> deli[201];
int dist[201];
int first_visit[201];

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
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < deli[cur].size(); i++)
        {
            int next = deli[cur][i].first;
            int ncost = deli[cur][i].second;
            if (dist[next] > cost + ncost)
            {
                if (cur == start)
                    first_visit[next] = next;
                else
                    first_visit[next] = first_visit[cur];
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        deli[a].push_back({b, c});
        deli[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            dist[k] = INF;
            first_visit[k] = 0;
        }
        dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                cout << "- ";
            else
                cout << first_visit[j] << " ";
        }
        cout << "\n";
    }
}