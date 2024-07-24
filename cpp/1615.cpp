#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr[2001];
long long tree[8001];

long long query(long long start, long long end, long long node, long long left, long long right)
{
    if (start > right || end < left)
        return 0;
    if (start >= left && end <= right)
        return tree[node];
    long long mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long idx)
{
    if (start > idx || end < idx)
        return;
    if (start == end)
    {
        tree[node] += 1;
        return;
    }
    long long mid = (start + end) / 2;
    update(start, mid, node * 2, idx);
    update(mid + 1, end, node * 2 + 1, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    long long answer = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 0; j < arr[i].size(); j++)
        {
            answer += query(1, n, 1, arr[i][j] + 1, n);
        }
        for (long long j = 0; j < arr[i].size(); j++)
        {
            update(1, n, 1, arr[i][j]);
        }
    }
    cout << answer;
}