#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;

long long arr[1000001];
long long tree[4000001];

long long sum(long long start, long long end, long long node, long long left, long long right)
{
    if (start > right || end < left)
        return 0;
    if (start >= left && end <= right)
        return tree[node];
    long long mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long idx, long long diff)
{
    if (start > idx || end < idx)
        return;
    tree[node] += diff;
    if (start == end)
        return;
    long long mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    while (k--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if (b > c)
                swap(b, c);
            cout << sum(1, n, 1, b, c) << "\n";
        }
        else
        {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, n, 1, b, diff);
        }
    }
}