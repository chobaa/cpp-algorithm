#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;
vector<long long> segtree;

long long m, n, k;

long long make_segtree(long long node, long long start, long long end)
{
    if (start == end)
        return segtree[node] = arr[start];

    long long mid = (start + end) / 2;
    return segtree[node] = (make_segtree(node * 2, start, mid) * make_segtree(node * 2 + 1, mid + 1, end)) % 1000000007;
}

long long query(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start)
        return 1;

    if (start >= left && end <= right)
        return segtree[node];

    long long mid = (start + end) / 2;

    return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

void update(long long node, long long start, long long end, long long idx, long long value)
{
    if (idx < start || idx > end)
        return;

    if (start == end)
    {
        segtree[node] = value;
        return;
    }
    long long mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    segtree[node] = (segtree[node * 2] * segtree[node * 2 + 1]) % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    arr.resize(n + 1);
    segtree.resize(n * 4);
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    make_segtree(1, 1, n);

    for (int i = 0; i < m + k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, n, b, c);
        else
            cout << query(1, 1, n, b, c) << "\n";
    }
}