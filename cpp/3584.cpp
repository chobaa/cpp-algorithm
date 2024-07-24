#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
int depth[10001];
int parent[10001];

void dfs(int cur)
{
    for (auto next : graph[cur])
    {
        if (depth[next] == -1)
        {
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            dfs(next);
        }
    }
}

int find_parent(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    while (depth[a] > depth[b])
    {
        a = parent[a];
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp = 0;
        cin >> n;
        // initialize
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
            depth[i] = -1;
            parent[i] = 0;
            temp += i;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            temp -= b;
        }
        depth[temp] = 0;
        parent[temp] = 0;
        dfs(temp);
        int a, b;
        cin >> a >> b;
        cout << find_parent(a, b) << "\n";
    }
}