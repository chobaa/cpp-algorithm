#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int tree[400004];

int n;

int min_index(int x, int y)
{
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    return arr[x] <= arr[y] ? x : y;
}

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;
    int mid = (start + end) / 2;
    return tree[node] = min_index(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int node, int left, int right)
{
    if (left <= start && end <= right)
        return tree[node];
    if (start > right || left > end)
        return -1;
    int mid = (start + end) / 2;
    return tree[node] = min_index(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

long long max_area(int left, int right)
{
    if (left > right)
        return -1;
    int min_idx = query(0, n - 1, 1, left, right);
    long long area = arr[min_idx] * (right - left + 1);
    if (min_idx + 1 <= right)
        area = max(max_area(min_idx + 1, right), area);
    if (min_idx - 1 >= left)
        area = max(max_area(left, min_idx - 1), area);
    return area;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(0, n - 1, 1);
    cout << max_area(0, n - 1);
}