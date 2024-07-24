#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];
int tree[4000001];

int top_value(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = top_value(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return top_value(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    for (int i = m; i <= n - m + 1; i++)
    {
        cout << query(1, n, 1, i - m + 1, i + m - 1) << " ";
    }
}