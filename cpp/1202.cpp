#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> jewel[300001];
int bag[300001];
priority_queue<int> pq;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(jewel, jewel + n);
    sort(bag, bag + k);

    int idx = 0;
    long long answer = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && bag[i] >= jewel[idx].first)
        {
            pq.push(jewel[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
}