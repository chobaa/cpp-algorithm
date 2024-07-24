#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> schedule;
priority_queue<int, vector<int>, greater<int>> pq;

int answer = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int end, start;
        cin >> start >> end;
        schedule.push_back({start, end});
    }

    sort(schedule.begin(), schedule.end());

    for (int i = 0; i < n; i++)
    {
        if (pq.empty() || pq.top() > schedule[i].first)
            pq.push(schedule[i].second);
        else
        {
            pq.pop();
            pq.push(schedule[i].second);
        }
    }

    cout << pq.size();

}