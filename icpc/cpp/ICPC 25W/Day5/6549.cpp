#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define sz 100001
#define INF 1e9 + 1

using namespace std;

int arr[100001];
pair<int, int> tree[400001];

pair<int, int> find_min(const pair<int, int> p1, const pair<int, int> p2)
{
    if (p1.first == p2.first)
    {
        if (p1.second < p2.second)
        {
            return p1;
        }
        else
            return p2;
    }
    else if (p1.first < p2.first)
        return p1;
    else
        return p2;
}

pair<int, int> query(long long left, long long right)
{
    left = left - 1 + sz;
    right = right - 1 + sz;
    pair<int, int> mn = {INF, INF};
    while (left <= right)
    {
        if (left % 2 == 1)
        {
            mn = find_min(tree[left], mn);
            left++;
        }
        if (right % 2 == 0)
        {
            mn = find_min(tree[right], mn);
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return mn;
}

void update(long long idx, long long value)
{
    int real_idx = idx;
    idx = idx - 1 + sz;
    tree[idx] = {value, real_idx};
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = find_min(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

long long cal_area(int start, int end)
{
    pair<int, int> mn = query(start, end);
    long long result = (long long)(end - start + 1) * mn.first;

    if (start <= mn.second - 1)
    {
        long long lresult = cal_area(start, mn.second - 1);
        result = max(result, lresult);
    }
    if (mn.second + 1 <= end)
    {
        long long rresult = cal_area(mn.second + 1, end);
        result = max(result, rresult);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= 400000; i++)
        {
            tree[i].first = tree[i].second = 0;
        }
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            update(i, arr[i]);
        }
        long long result = cal_area(1, n);
        cout << result << "\n";
    }
}