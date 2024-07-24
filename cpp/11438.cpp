#include <bits/stdc++.h>
using namespace std;
#define MAX 18

int n, m;

int parent[MAX][100001];
int depth[100001];

vector<int> node[100001];

void make_tree(int cur)
{
    for (int next : node[cur])
    {
        if (depth[next] == -1)
        {
            parent[0][next] = cur;
            depth[next] = depth[cur] + 1;
            make_tree(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    make_tree(1);
    for (int k = 1; k < MAX; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (depth[a] < depth[b])
            swap(a, b);
        int diff = depth[a] - depth[b], j = 0;
        while (diff)
        {
            if (diff % 2)
            {
                a = parent[j][a];
            }
            j++;
            diff /= 2;
        }
        if (a != b)
        {
            for (int j = MAX - 1; j >= 0; j--)
            {
                if (parent[j][a] != parent[j][b])
                {
                    a = parent[j][a];
                    b = parent[j][b];
                }
            }
            a = parent[0][a];
        }
        cout << a << "\n";
    }
}