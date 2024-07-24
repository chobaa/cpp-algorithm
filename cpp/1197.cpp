#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];
vector<pair<int, pair<int, int>>> tree;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void make_union(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[b] = a;
}

bool sameparent(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    int v, e, result = 0;
    cin >> v >> e;
    int start, end, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> start >> end >> weight;
        tree.push_back({weight, {start, end}});
    }
    sort(tree.begin(), tree.end());
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        if (!sameparent(tree[i].second.first, tree[i].second.second))
        {
            make_union(tree[i].second.first, tree[i].second.second);
            result += tree[i].first;
        }
    }
    cout << result;
}