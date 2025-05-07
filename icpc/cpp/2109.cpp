#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[10001];

int main()
{
    int answer = 0;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if (v[i].first < pq.size())
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}