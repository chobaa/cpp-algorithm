#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[8000001];

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
    if (tree[node * 2] >= target)
        return query(start, mid, node * 2, target);
    else
        return query(mid + 1, end, node * 2 + 1, target - tree[node * 2]);
}

void update(int start, int end, int node, int idx, int diff)
{
    if (idx < start || end < idx)
        return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            update(1, 2000000, 1, b, 1);
        }
        else
        {
            int target = query(1, 2000000, 1, b);
            update(1, 2000000, 1, target, -1);
            cout << target << "\n";
        }
    }
}