#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc, n, m, w;

bool BellmanFord(vector<pair<int, pair<int, int>>> road)
{
    vector<int> dist(n + 1, 30000000);
    dist[1] = 0;
    for (int t = 0; t < n; t++)
    {
        for (int i = 0; i < road.size(); i++)
        {
            int start = road[i].first;
            int to = road[i].second.first;
            int weight = road[i].second.second;
            if (dist[to] > dist[start] + weight)
                dist[to] = dist[start] + weight;
        }
    }
    for (int i = 0; i < road.size(); i++)
    {
        int start = road[i].first;
        int to = road[i].second.first;
        int weight = road[i].second.second;
        if (dist[to] > dist[start] + weight)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> w;

        vector<pair<int, pair<int, int>>> road;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            road.push_back({s, {e, t}});
            road.push_back({e, {s, t}});
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            road.push_back({s, {e, -t}});
        }
        if (BellmanFord(road))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}