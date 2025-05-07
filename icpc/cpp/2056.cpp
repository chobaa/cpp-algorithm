#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> graph[10001];
int indegree[10001];
int worktime[10001];
int endtime[10001];
int answer = 0;
queue<int> q;

void topsort()
{
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            endtime[i] = worktime[i];
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto next : graph[cur])
        {
            endtime[next] = max(endtime[cur], endtime[next]);
            if (--indegree[next] == 0)
            {
                endtime[next] += worktime[next];
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> worktime[i] >> indegree[i];
        for (int j = 0; j < indegree[i]; j++)
        {
            int temp;
            cin >> temp;
            graph[temp].push_back(i);
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
    {
        answer = max(answer, endtime[i]);
    }
    cout << answer;
}