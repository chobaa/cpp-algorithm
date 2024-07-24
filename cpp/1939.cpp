#include <iostream>
#include <vector>
#include <queue>
#define FASTIO      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios::sync_with_stdio(false);

using namespace std;
vector<pair<int, int>> map[10001];

int n, m, s, e;
bool visited[10001];

bool find_weight(int cost)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == e)
            return true;
        for (int i = 0; i < map[cur].size(); i++)
        {
            int next = map[cur][i].first;
            int next_cost = map[cur][i].second;
            if (!visited[next] && cost <= next_cost)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
    FASTIO
    cin >> n >> m;
    int max_cost = 0;
    for (int i = 0; i < m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        map[start].push_back({end, weight});
        map[end].push_back({start, weight});
        max_cost = max(max_cost, weight);
    }
    cin >> s >> e;
    int left = 0;
    int right = max_cost;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (find_weight(mid))
            left = mid + 1;
        else
            right = mid - 1;
        for (int i = 0; i < n + 1; i++)
        {
            visited[i] = false;
        }
    }
    cout << right;
}