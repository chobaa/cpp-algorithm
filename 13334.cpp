#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        v.push_back({a, b});
    }
    int l, answer = 0;
    cin >> l;
    sort(v.begin(), v.end(), cmp);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int start = v[i].first;
        int end = v[i].second;
        if (end - start > l)
        {
            continue;
        }
        pq.push(-start);
        while (!pq.empty())
        {
            if (end + pq.top() <= l)
            {
                break;
            }
            else
                pq.pop();
        }
        if (answer < pq.size())
            answer = pq.size();
    }
    cout << answer;
}