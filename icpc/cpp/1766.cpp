#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;
vector<vector<int>> map;
int ingree[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> n >> m;
    map.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ingree[v]++;
        map[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ingree[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        cout << node << " ";
        for (int i = 0; i < map[node].size(); i++)
        {
            ingree[map[node][i]]--;
            if (ingree[map[node][i]] == 0)
            {
                pq.push(map[node][i]);
            }
        }
    }
}