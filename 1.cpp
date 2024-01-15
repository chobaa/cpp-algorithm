#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void update(vector<int> &tree, int node, int start, int end, int index, int diff)
{
    if (!(start <= index && index <= end))
        return;

    tree[node] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;

        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(vector<int> &tree, int node, int start, int end, int val)
{
    int get;
    int mid = (start + end) / 2;

    if (start == end)
    {
        tree[node]--;
        return start;
    }

    if (tree[node * 2] >= val)
        get = query(tree, node * 2, start, mid, val);
    else
        get = query(tree, node * 2 + 1, mid + 1, end, val - tree[node * 2]);

    tree[node]--;
    return get;
}
int main()
{
    int n;
    scanf("%d", &n);

    vector<int> arr(n + 1);

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);

    vector<int> tree(tree_size);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        update(tree, 1, 0, n - 1, i, 1);
    }

    vector<int> ans(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int get = query(tree, 1, 0, n - 1, arr[i] + 1);

        ans[get + 1] = i + 1;
    }

    for (int i = n; i >= 1; i--)
        printf("%d ", ans[i]);
    return 0;
}