#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
vector<pair<int, int>> result;
vector<int> tree(2000001, 0);

int query(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return;
    tree[node] += 1;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
    }
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n);
    result.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].second = i;
        cin >> arr[i].first;
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        arr[i].first = n - i;
    }
    for (int i = 0; i < n; i++)
    {
        result[i].first = arr[i].second;
        result[i].second = query(0, n - 1, 1, 0, arr[i].second - 1);
        update(0, n - 1, 1, arr[i].second);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < n; i++)
    {
        cout << result[i].second + 1 << "\n";
    }
}