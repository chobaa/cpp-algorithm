#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

int parent[17][40001];
int cost[17][40001];
int depth[40001];

vector<pair<int, int>> node[40001];

void make_tree(int x)
{
    for (int i = 0; i < node[x].size(); i++)
    {
        int next = node[x][i].first;
        int ncost = node[x][i].second;
        if (depth[next] == -1)
        {
            depth[next] = depth[x] + 1;
            parent[0][next] = x;
            cost[0][next] = ncost;
            make_tree(next);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    make_tree(1);
    for (int k = 1; k <= 16; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int prevparent = parent[k - 1][i];
            int prevcost = cost[k - 1][i];
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
            cost[k][i] = prevcost + cost[k - 1][prevparent];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, answer = 0;
        cin >> a >> b;
        if (depth[a] < depth[b])
            swap(a, b);
        int diff = depth[a] - depth[b], j = 0;
        while (diff)
        {
            if (diff % 2)
            {
                answer += cost[j][a];
                a = parent[j][a];
            }
            j++;
            diff /= 2;
        }
        if (a != b)
        {
            for (int j = 16; j >= 0; j--)
            {
                if (a == b)
                {
                    answer += cost[0][a];
                    break;
                }
                if (parent[j][a] != parent[j][b])
                {
                    answer += cost[j][a] + cost[j][b];
                    a = parent[j][a];
                    b = parent[j][b];
                }
            }
            answer += cost[0][a] + cost[0][b];
        }
        cout << answer << "\n";
    }
}