#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;

long long a[500001];
long long b[1000001];
long long tree[2000001];

long long sum(long long start, long long end, long long node, long long left, long long right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && right >= end)
        return tree[node];

    long long mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long start, long long end, long long node, long long idx, long long value)
{
    if (start > idx || end < idx)
        return;
    tree[node] += value;
    if (start != end)
    {
        long long mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
    }
}

int main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // b배열에 특정 숫자의 idx를 기록해둠
    for (long long i = 1; i <= n; i++)
    {
        long long c;
        cin >> c;
        b[c] = i;
    }
    long long result = 0;
    for (long long i = 1; i <= n; i++)
    {
        // 숫자의 idx보다 큰 값이 이미 들어왔는지 확인해서 sum 갱신
        long long idx = b[a[i]];
        result += sum(1, n, 1, idx + 1, n);
        // 해당 idx를 1로 수정
        update(1, n, 1, idx, 1);
    }
    cout << result;
}