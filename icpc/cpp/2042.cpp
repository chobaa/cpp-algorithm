#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, k;
vector<long long> tree;
vector<long long> list;

long long make_segtree(long long node, long long start, long long end)
{
    if (start == end)
        return tree[node] = list[start];
    long long mid = (start + end) / 2;
    long long left_result = make_segtree(node * 2, start, mid);
    long long right_result = make_segtree(node * 2 + 1, mid + 1, end);
    tree[node] = left_result + right_result;

    return tree[node];
}

long long sum(long long node, long long start, long long end, long long left, long long right)
{
    if (end < left || start > right)
        return 0;
    if (start >= left && end <= right)
        return tree[node];

    long long mid = (start + end) / 2;
    long long left_sum = sum(node * 2, start, mid, left, right);
    long long right_sum = sum(node * 2 + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

void update(long long node, long long start, long long end, long long idx, long long diff)
{
    if (idx < start || idx > end)
        return;
    tree[node] += diff;

    if (start != end)
    {
        long long mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main()
{
    cin >> n >> m >> k;
    tree.resize(n * 4);
    list.resize(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    make_segtree(1, 0, n - 1);

    for (long long i = 0; i < m + k; i++)
    {
        long long oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 1)
        {
            long long diff = b - list[a - 1];
            list[a - 1] = b;
            update(1, 0, n - 1, a - 1, diff);
        }
        else
            cout << sum(1, 0, n - 1, a - 1, b - 1) << "\n";
    }
}