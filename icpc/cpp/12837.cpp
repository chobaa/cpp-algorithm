#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;

long long tree[4000001];

long long query(long long start, long long end, long long node, long long left, long long right)
{
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    long long mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long idx, long long diff)
{
    if (start > idx || end < idx)
        return;
    tree[node] += diff;
    if (start != end)
    {
        long long mid = (start + end) / 2;
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
    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
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