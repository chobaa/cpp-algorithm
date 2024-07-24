#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<int> result;
stack<int> s;
bool visited[32001];

void dfs(int i)
{
    visited[i] = true;
    for (int j = 0; j < map[i].size(); j++)
    {
        if (!visited[map[i][j]])
        {
            dfs(map[i][j]);
        }
    }
    s.push(i);
}

int main()
{
    cin >> n >> m;
    map.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
        }
    }
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    for (auto num : result)
    {
        cout << num << " ";
    }
}