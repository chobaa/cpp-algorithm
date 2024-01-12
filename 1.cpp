#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ar[100001];
int n;

vector<int> seg_idx;

inline int mid(int s, int e) { return s + (e - s) / 2; }

int cmpidx(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (ar[a] < ar[b])
        return a;
    return b;
}

int init_min(int node, int start, int end)
{
    if (start == end)
        return seg_idx[node] = end;
    int m = mid(start, end);
    int l = init_min(node * 2, start, m);
    int r = init_min(node * 2 + 1, m + 1, end);
    return seg_idx[node] = cmpidx(l, r);
}

int query_min(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return -1;
    if (l <= start && end <= r)
        return seg_idx[node];
    int m = mid(start, end);
    return cmpidx(
        query_min(node * 2, start, m, l, r),
        query_min(node * 2 + 1, m + 1, end, l, r));
}

ll init_sum(vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = ar[end];
    int m = mid(start, end);
    return tree[node] = init_sum(tree, node * 2, start, m) + init_sum(tree, node * 2 + 1, m + 1, end);
}

ll query_sum(vector<ll> &tree, int node, int start, int end, int l, int r)
{
    if (start > r || l > end)
        return 0;
    if (l <= start && end <= r)
        return tree[node];
    int m = mid(start, end);
    return query_sum(tree, node * 2, start, m, l, r) + query_sum(tree, node * 2 + 1, m + 1, end, l, r);
}

ll query(vector<ll> &tree, int start, int end)
{
    if (start == end)
        return (ll)ar[end] * ar[end];
    int idx = query_min(1, 1, n, start, end);
    ll res = ar[idx] * query_sum(tree, 1, 1, n, start, end);
    if (start < idx)
        res = max(res, query(tree, start, idx - 1));
    if (idx < end)
        res = max(res, query(tree, idx + 1, end));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    seg_idx.resize(n * 4);
    vector<ll> sum_tree(n * 4);

    for (int i = 1; i <= n; ++i)
        cin >> ar[i];
    init_min(1, 1, n);
    init_sum(sum_tree, 1, 1, n);
    cout << query(sum_tree, 1, n);
}