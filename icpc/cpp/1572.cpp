#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[250001];
int tree[250001];

void update(int start, int end, int node, int idx, int value)
{
    if (idx < start || idx > end)
        return;
    tree[node] += value;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
    }
}

int query(int start, int end, int node, int target)
{
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] >= target)
        return query(start, mid, node * 2, target);
    else
        return query(mid + 1, end, node * 2 + 1, target - tree[node * 2]);
}

long long answer = 0;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(0, 65536, 1, arr[i], 1);
        if (i >= k)
        {
            answer += query(0, 65536, 1, (k + 1) / 2);
            update(0, 65536, 1, arr[i - k + 1], -1);
        }
    }
    cout << answer;
}