#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[100001];
long long tree[4000001];
long long index_tree[4000001];

long long n;

long long min_index(long long a, long long b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (arr[a] < arr[b])
        return a;
    return b;
}

long long init(long long start, long long end, long long node)
{
    if (start == end)
        return tree[node] = arr[start];
    long long mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long index_init(long long start, long long end, long long node)
{
    if (start == end)
        return index_tree[node] = start;
    long long mid = (start + end) / 2;
    return index_tree[node] = min_index(index_init(start, mid, node * 2), (index_init(mid + 1, end, node * 2 + 1)));
}

long long query_index(long long start, long long end, long long node, long long left, long long right)
{
    if (end < left || start > right)
        return -1;
    if (left <= start && end <= right)
        return index_tree[node];
    if (start != end)
    {
        long long mid = (start + end) / 2;
        return min_index(query_index(start, mid, node * 2, left, right), query_index(mid + 1, end, node * 2 + 1, left, right));
    }
}

long long query_sum(long long start, long long end, long long node, long long left, long long right)
{
    if (end < left || start > right)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    if (start != end)
    {
        long long mid = (start + end) / 2;
        return query_sum(start, mid, node * 2, left, right) + query_sum(mid + 1, end, node * 2 + 1, left, right);
    }
}

// 내가 구해온 idx는 구간 사이의 최솟값이다.
// 따라서 왼쪽이나 오른쪽에는 반드시 더 큰값을 곱할 기회가 남아있고,
// 그 값과 result를 곱했을 때에 곱이 영향을 크게줌으로 값이 더 커질 가능성이 있다.
long long query(long long start, long long end)
{
    if (start == end)
        return arr[start] * arr[start];
    long long idx = query_index(1, n, 1, start, end);
    long long sum = query_sum(1, n, 1, start, end);
    long long result = arr[idx] * sum;
    if (start < idx)
        result = max(query(start, idx - 1), result);
    if (idx < end)
        result = max(query(idx + 1, end), result);
    return result;
}

int main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    index_init(1, n, 1);
    cout << query(1, n);
}