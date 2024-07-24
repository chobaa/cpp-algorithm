#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[400001];

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int query(int start, int end, int node, int target)
{
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] < target)
        return query(mid + 1, end, node * 2 + 1, target - tree[node * 2]);
    else
        return query(start, mid, node * 2, target);
}

void update(int start, int end, int node, int idx)
{
    if (start > idx || end < idx)
        return;
    tree[node] -= 1;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    init(1, n, 1);
    vector<int> result(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        int idx = query(1, n, 1, temp + 1);
        update(1, n, 1, idx);
        result[idx] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << "\n";
    }
}