#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> road[10001];
vector<pair<int, int>> rev_road[10001];

int dist[10001];
bool visited[10001];

int s, e, answer = 0;

void dijkstra()
{
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (int i = 0; i < road[cur].size(); i++)
        {
            int next = road[cur][i].first;
            int ncost = road[cur][i].second;
            if (dist[next] < cost + ncost)
            {
                dist[next] = cost + ncost;
                q.push({next, dist[next]});
            }
        }
    }
}

void find_road()
{
    queue<pair<int, int>> q;
    q.push({e, dist[e]});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (int i = 0; i < rev_road[cur].size(); i++)
        {
            int next = rev_road[cur][i].first;
            int ncost = rev_road[cur][i].second;
            if (dist[next] == cost - ncost)
            {
                answer++;
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push({next, dist[next]});
                }
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    // dist 초기화
    for (int i = 0; i <= n; i++)
    {
        dist[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({b, c});
        rev_road[b].push_back({a, c});
    }
    cin >> s >> e;
    dijkstra();
    find_road();
    cout << dist[e] << "\n"
         << answer << "\n";
}