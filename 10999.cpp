#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, k;

long long arr[1000001];
long long lazy[4000001];
long long tree[4000001];

void lazy_update(long long start, long long end, long long node)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long init(long long start, long long end, long long node)
{
    if (start == end)
        return tree[node] = arr[start];
    long long mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long query(long long start, long long end, long long node, long long left, long long right)
{
    lazy_update(start, end, node);
    if (right < start || end < left)
        return 0;
    if (left <= start && right >= end)
        return tree[node];
    long long mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long left, long long right, long long value)
{
    lazy_update(start, end, node);
    if (right < start || end < left)
        return;
    if (left <= start && right >= end)
    {
        tree[node] += (end - start + 1) * value;
        if (start != end)
        {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    long long mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, value);
    update(mid + 1, end, node * 2 + 1, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    for (long long i = 0; i < m + k; i++)
    {
        long long a, b, c, d;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update(1, n, 1, b, c, d);
        }
        if (a == 2)
        {
            cin >> b >> c;
            cout << query(1, n, 1, b, c) << "\n";
        }
    }
}