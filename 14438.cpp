#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100001];
int tree[400001];

int n, m;

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx, int num)
{
    if (start > idx || end < idx)
        return tree[node];
    if (start == end)
        return tree[node] = num;
    int mid = (start + end) / 2;
    return tree[node] = min(update(start, mid, node * 2, idx, num), update(mid + 1, end, node * 2 + 1, idx, num));
}

int query(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 1000000001;
    if (start >= left && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;

    init(1, n, 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, n, 1, b, c);
        }
        else if (a == 2)
        {
            cout << query(1, n, 1, b, c) << "\n";
        }
    }
}
