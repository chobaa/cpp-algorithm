#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int arr[100001];
int tree[400001];

int min_index(int y, int x)
{
    if (arr[x] == arr[y])
        return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
}

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;
    int mid = (start + end) / 2;
    tree[node] = min_index(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx, int value)
{
    if (start > idx || end < idx)
        return tree[node];
    if (start == end)
        return tree[node];
    int mid = (start + end) / 2;
    return tree[node] = min_index(update(start, mid, node * 2, idx, value), update(mid + 1, end, node * 2 + 1, idx, value));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(1, n, 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int idx, value;
            scanf("%d %d", &idx, &value);
            arr[idx] = value;
            update(1, n, 1, idx, value);
        }
        if (op == 2)
            printf("%d\n", tree[1]);
    }
}