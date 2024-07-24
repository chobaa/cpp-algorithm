#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> tree;
vector<bool> visited;
int dp[1000001][2];

void dfs(int node)
{
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    for (int i = 0; i < tree[node].size(); i++)
    {
        int cur_node = tree[node][i];
        if (visited[cur_node])
            continue;

        dfs(cur_node);

        dp[node][0] += dp[cur_node][1];
        dp[node][1] += min(dp[cur_node][0], dp[cur_node][1]);
    }
}

int main()
{
    cin >> n;
    tree.resize(n + 1);
    visited.resize(n + 1);
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        visited[i] = false;
    }
    visited[n] = false;
    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
}