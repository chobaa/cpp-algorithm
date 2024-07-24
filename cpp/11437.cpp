#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int parent = 0;
    vector<int> child;
    int depth = 0;
};

vector<vector<int>> map;
vector<bool> visited;
vector<node> tree;

int n, m;

void make_tree()
{
    queue<int> q;
    q.push(1);
    tree[1].depth = 0;
    tree[1].parent = -1;
    visited[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < map[cur].size(); i++)
        {
            int next = map[cur][i];
            if (!visited[next])
            {
                tree[next].parent = cur;
                tree[next].depth = tree[cur].depth + 1;
                tree[cur].child.push_back(next);
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    tree.resize(n + 1);
    map.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    make_tree();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        while (tree[a].depth != tree[b].depth)
        {
            if (tree[a].depth > tree[b].depth)
            {
                a = tree[a].parent;
            }
            else
                b = tree[b].parent;
        }
        while (a != b)
        {
            a = tree[a].parent;
            b = tree[b].parent;
        }
        cout << a << "\n";
    }
}