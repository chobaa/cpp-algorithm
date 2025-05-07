#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long n, m, k;

long long sz = 1000010;

long long arr[1000010];
long long tree[4000010];

long long query(long long left, long long right)
{
    left = left - 1 + sz;
    right = right - 1 + sz;
    long long sum = 1;
    while (left <= right)
    {
        if (left % 2 == 1)
        {
            sum = (sum * tree[left]) % MOD;
            left++;
        }
        if (right % 2 == 0)
        {
            sum = (sum * tree[right]) % MOD; 
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return sum;
}

void update(long long idx, long long value)
{
    idx = idx - 1 + sz;
    tree[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
    }
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
    for (long long i = 1; i <= n; i++)
    {
        update(i, arr[i]);
    }
    for (long long i = 0; i < m + k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 2)
            cout << query(b, c) << "\n";
        else
            update(b, c);
    }
}