#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;

long long candy[MAX + 1] = {
    0,
};
long long tree[MAX * 4 + 1];

long long query(long long start, long long end, long long node, long long k)
{

    if (start == end)
        return end;
    long long mid = (start + end) / 2;
    if (tree[node * 2] >= k)
        return query(start, mid, node * 2, k);
    else
        return query(mid + 1, end, node * 2 + 1, k - tree[node * 2]);
}

void update(long long start, long long end, long long node, long long idx, long long value)
{
    if (start > idx || end < idx)
        return;
    if (start == end)
    {
        tree[node] = value;
        return;
    }
    long long mid = (start + end) / 2;
    update(start, mid, node * 2, idx, value);
    update(mid + 1, end, node * 2 + 1, idx, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    while (n--)
    {
        long long command;
        cin >> command;
        if (command == 1)
        {
            long long k;
            cin >> k;
            long long t = query(1, MAX, 1, k);
            cout << t << "\n";
            update(1, MAX, 1, t, candy[t] - 1);
            candy[t] -= 1;
        }
        if (command == 2)
        {
            long long type, cnt;
            cin >> type >> cnt;
            update(1, MAX, 1, type, candy[type] + cnt);
            candy[type] += cnt;
        }
    }
}