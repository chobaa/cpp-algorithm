#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;

vector<long long> min_segtree;
vector<long long> list;

void make_segtree(long long node, long long start, long long end)
{
    if (start == end)
    {
        min_segtree[node] = list[start];
        return;
    }
    else
    {
        long long mid = (start + end) / 2;
        make_segtree(node * 2, start, mid);
        make_segtree(node * 2 + 1, mid + 1, end);
        min_segtree[node] = min(min_segtree[node * 2], min_segtree[node * 2 + 1]);
        return;
    }
}

int findMinMax(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return INT32_MAX;
    else if (left <= start && right >= end)
    {
        return min_segtree[node];
    }
    else
    {
        long long mid = (start + end) / 2;
        int l, r;
        l = findMinMax(node * 2, start, mid, left, right);
        r = findMinMax(node * 2 + 1, mid + 1, end, left, right);
        return min(l, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    min_segtree.resize(n * 4);
    list.resize(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> list[i];
    }
    make_segtree(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int result;
        result = findMinMax(1, 1, n, a, b);
        cout << result << "\n";
    }
}