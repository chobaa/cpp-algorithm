#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

double dist_w[2][4001];
int dist_f[4001];

vector<pair<int, int>> road[4001];

int n, m;

void dijkstra_f(int start, int dist[])
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < road[cur].size(); i++)
        {
            int next = road[cur][i].first;
            int ncost = road[cur][i].second;
            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

void dijkstra_w(int start, double dist[2][4001])
{
    priority_queue<pair<double, pair<int, int>>> pq;
    pq.push({0, {start, 1}});
    while (!pq.empty())
    {
        double cost = -pq.top().first;
        int cur = pq.top().second.first;
        int boost = pq.top().second.second;
        pq.pop();

        if (dist[boost][cur] < cost)
            continue;
        for (int i = 0; i < road[cur].size(); i++)
        {
            int next = road[cur][i].first;
            double ncost = 0;
            if (boost == 0)
            {
                ncost = road[cur][i].second * 2.0;
                if (dist[1][next] > cost + ncost)
                {
                    dist[1][next] = cost + ncost;
                    pq.push({-dist[1][next], {next, (boost + 1) % 2}});
                }
            }
            else
            {
                ncost = road[cur][i].second / 2.0;
                if (dist[0][next] > cost + ncost)
                {
                    dist[0][next] = cost + ncost;
                    pq.push({-dist[0][next], {next, (boost + 1) % 2}});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    for (int i = 0; i < 4001; i++)
    {
        dist_f[i] = INF;
        dist_w[0][i] = INF;
        dist_w[1][i] = INF;
    }
    dijkstra_w(1, dist_w);
    dijkstra_f(1, dist_f);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (dist_f[i] < dist_w[0][i] && dist_f[i] < dist_w[1][i])
            cnt++;
    }
    cout << cnt;
}