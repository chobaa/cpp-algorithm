#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

vector<int> arr;
vector<int> tree;

int invert(int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = invert(arr[start]);
    int mid = (start + end) / 2;
    return tree[node] = invert(init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 1;
    if (start >= left && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return invert(query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right));
}

int update(int start, int end, int node, int idx, int value)
{
    if (start > idx || end < idx)
        return tree[node];
    int mid = (start + end) / 2;
    if (start == end)
    {
        return tree[node] = invert(value);
    }
    return tree[node] = update(start, mid, node * 2, idx, value) * update(mid + 1, end, node * 2 + 1, idx, value);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    arr.resize(100001);
    tree.resize(400001);
    while (cin >> n >> k)
    {
        arr.clear();
        tree.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        init(1, n, 1);
        for (int i = 0; i < k; i++)
        {
            char order;
            cin >> order;
            if (order == 'C')
            {
                int a, b;
                cin >> a >> b;
                update(1, n, 1, a, b);
                arr[a] = b;
            }
            if (order == 'P')
            {
                int a, b;
                cin >> a >> b;
                int result = query(1, n, 1, a, b);
                if (result == 0)
                    cout << '0';
                else if (result < 0)
                    cout << '-';
                else
                    cout << '+';
            }
        }
        cout << "\n";
    }
}