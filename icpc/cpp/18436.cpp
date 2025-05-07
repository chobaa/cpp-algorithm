#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int tree[400001];

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start] % 2;
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, int value)
{
    if (start > idx || end < idx)
        return;
    tree[node] += value;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
    }
}

int query(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 0;
    if (left <= start && right >= end)
        return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int diff = c % 2 - arr[b] % 2;
            update(1, n, 1, b, diff);
            arr[b] = c;
        }
        if (a == 2)
        {
            if (b > c)
                swap(b, c);
            cout << c - b + 1 - query(1, n, 1, b, c) << "\n";
        }
        if (a == 3)
        {
            if (b > c)
                swap(b, c);
            cout << query(1, n, 1, b, c) << "\n";
        }
    }
}