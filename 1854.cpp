#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m, k;

#define INF 987654321

vector<pair<int, int>> v[1001];
priority_queue<int> dist[1001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1].push(0);
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if (dist[next].size() < k)
            {
                dist[next].push(cost + ncost);
                pq.push({-(cost + ncost), next});
            }
            else if (dist[next].top() > cost + ncost)
            {
                dist[next].pop();
                dist[next].push(cost + ncost);
                pq.push({-(cost + ncost), next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    string str;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (dist[i].size() == k)
            cout << dist[i].top() << "\n";
        else
            cout << -1 << "\n";
    }
}