#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const long long INF = 1e12 + 300000;
const long long MOD = 1e9 + 9;

using namespace std;

long long n, m, x, y;

vector<pair<long long, long long>> graph[100001];

long long dist[100001];
long long cnt[100001];
long long shortestcnt[100001];

void dijkstra()
{
    dist[x] = 0;
    priority_queue<pair<long long, long long>> pq;
    pq.push({0, x});
    while (!pq.empty())
    {
        long long cur = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if (cost > dist[cur])
            continue;
        for (auto temp : graph[cur])
        {
            long long next = temp.second;
            long long ncost = temp.first;
            if (dist[next] >= cost + ncost)
            {
                if (dist[next] == cost + ncost)
                {
                    if (cnt[next] > cnt[cur] + 1)
                    {
                        cnt[next] = cnt[cur] + 1;
                        shortestcnt[next] = shortestcnt[cur];
                    }
                    else if (cnt[next] == cnt[cur] + 1)
                    {
                        shortestcnt[next] = (shortestcnt[cur] + shortestcnt[next]) % MOD;
                    }
                }
                else
                {
                    shortestcnt[next] = shortestcnt[cur];
                    cnt[next] = cnt[cur] + 1;
                    dist[next] = cost + ncost;
                    pq.push({-dist[next], next});
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
    cin >> n >> m >> x >> y;
    for (long long i = 0; i < m; i++)
    {
        long long from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({weight, to});
    }
    for (long long i = 1; i <= n; i++)
    {
        dist[i] = INF;
        shortestcnt[i] = 1;
    }
    dijkstra();
    if (dist[y] == INF)
        cout << -1 << "\n";
    else
    {
        cout << dist[y] << "\n";
        cout << cnt[y] << "\n";
        cout << shortestcnt[y] << "\n";
    }
}