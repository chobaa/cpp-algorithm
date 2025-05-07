#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int sz = 100010;

int arr[100010];
int tree[400010];

int query(int left, int right)
{
    left = left - 1 + sz;
    right = right - 1 + sz;
    int sum = 0;
    while (left <= right)
    {
        if (left % 2 == 1)
        {
            sum += tree[left];
            left++;
        }
        if (right % 2 == 0)
        {
            sum += tree[right];
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return sum;
}

void update(int idx, int value)
{
    if (value % 2 == 0)
        value = 1;
    else
        value = 0;
    idx = idx - 1 + sz;
    tree[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(i, arr[i]);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        else if (a == 2)
            cout << query(b, c) << "\n";
        else
            cout << c - b + 1 - query(b, c) << "\n";
    }
}