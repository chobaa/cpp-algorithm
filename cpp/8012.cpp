#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

vector<int> graph[30001];
int depth[30001];
int parent[30001][20];

void find_parent(int cur)
{
    for (auto next : graph[cur])
    {
        if (depth[next] == -1)
        {
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            find_parent(next);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b], j = 0;
    while (diff)
    {
        if (diff % 2)
        {
            a = parent[a][j];
        }
        j++;
        diff /= 2;
    }
    if (a == b)
        return a;
    else
    {
        for (int i = 19; i >= 0; i--)
        {
            if (parent[a][i] != parent[b][i])
            {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
    }
    return parent[a][0];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(depth, -1, sizeof(depth));
    memset(parent, 0, sizeof(parent));
    depth[1] = 0;
    find_parent(1);
    int answer = 0;
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1])
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    cin >> m;
    int prev, now;
    cin >> prev;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> now;
        int common = lca(prev, now);
        answer += depth[prev] + depth[now] - 2 * depth[common];
        prev = now;
    }
    cout << answer;
}