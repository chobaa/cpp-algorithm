#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;

long long arr[100001];
long long tree[400001];

long long init(long long start, long long end, long long node)
{
    if (start == end)
        return tree[node] = arr[start];
    long long mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long query(long long start, long long end, long long node, long long left, long long right)
{

    if (left <= start && end <= right)
        return tree[node];
    if (left > end || right < start)
        return 0;
    long long mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long idx, long long diff)
{
    if (idx > end || idx < start)
        return;
    tree[node] += diff;
    long long mid = (start + end) / 2;
    if (start != end)
    {
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    for (long long i = 0; i < m; i++)
    {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << query(1, n, 1, x, y) << "\n";
        long long diff = b - arr[a];
        arr[a] = b;
        update(1, n, 1, a, diff);
    }
}