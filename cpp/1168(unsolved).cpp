#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[400001];

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int query(int start, int end, int node, int order)
{
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (order <= tree[node * 2])
        return query(start, mid, node * 2, order);
    else
        return query(mid + 1, end, node * 2 + 1, order);
}

void update(int start, int end, int node, int idx)
{
    tree[node] -= 1;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
    }
}

int main()
{
    int n, k;
    int idx = 1;
    int size = n + 1;
    cin >> n >> k;
    init(1, n, 1);
    for (int i = 0; i < n; i++)
    {
        size--;
        idx += k - 1;
        if (idx % size == 0)
            idx = size;
        else if (idx > size)
            idx %= size;

        int num = query(1, n, 1, idx);
        cout << num << " ";
        update(1, n, 1, num);
    }
}