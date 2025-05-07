#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 18

vector<int> graph[100001];
int depth[100001];
int parent[MAX][100001];

void make_tree(int cur)
{
    for (auto next : graph[cur])
    {
        if (depth[next] == -1)
        {
            depth[next] = depth[cur] + 1;
            parent[0][next] = cur;
            make_tree(next);
        }
    }
}

int find_parent(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int k = MAX; k >= 0; k--)
    {
        if (depth[a] - (1 << k) >= depth[b])
        {
            a = parent[k][a];
        }
    }

    if (a == b)
        return a;

    for (int k = MAX - 1; k >= 0; k--)
    {
        if (parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    return parent[0][a];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        depth[i] = -1;
    }
    depth[1] = 0;
    parent[0][1] = 0;
    make_tree(1);

    // binary lifting
    for (int k = 1; k < MAX; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << find_parent(a, b) << "\n";
    }
}