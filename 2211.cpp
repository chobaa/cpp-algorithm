#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define INF 987654321;

int n, m;

vector<pair<int, int>> v[1001];
int dist[1001];
int parent[1001];
set<pair<int, int>> answer;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if (dist[next] > cost + ncost)
            {
                parent[next] = cur;
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
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        parent[i] = i;
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != i)
        {
            answer.insert({max(parent[i], i), min(parent[i], i)});
        }
    }
    cout << answer.size() << "\n";
    for (auto temp : answer)
    {
        cout << temp.first << " " << temp.second << "\n";
    }
}