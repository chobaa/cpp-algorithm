#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define INF 2100000000

using namespace std;

int n, m, t, s, g, h;

vector<pair<int, int>> road[2001];
vector<int> goal;
int dist_s[2001];
int dist_g[2001];
int dist_h[2001];

void dijkstra(int start, int dist[2001])
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < 2001; i++)
        {
            road[i].clear();
            dist_s[i] = INF;
            dist_g[i] = INF;
            dist_h[i] = INF;
        }
        goal.clear();
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            road[a].push_back({b, c});
            road[b].push_back({a, c});
        }
        for (int i = 0; i < t; i++)
        {
            int a;
            cin >> a;
            goal.push_back(a);
        }
        dijkstra(s, dist_s);
        dijkstra(g, dist_g);
        dijkstra(h, dist_h);
        sort(goal.begin(), goal.end());
        for (int i = 0; i < t; i++)
        {
            int dest = goal[i];
            if (dist_s[dest] == dist_s[g] + dist_g[h] + dist_h[dest])
                cout << dest << " ";
            else if (dist_s[dest] == dist_s[h] + dist_h[g] + dist_g[dest])
                cout << dest << " ";
        }
        cout << "\n";
    }
}