#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

vector<int> graph[1001];
int visitedCnt = 1;
int visited[1001];
int match[1001];

bool bipartiteMatch(int x)
{
    for (int i = 0; i < graph[x].size(); i++)
    {
        int next = graph[x][i];
        if (visited[next] == visitedCnt)
            continue;
        visited[next] = visitedCnt;
        if (match[next] == 0 || bipartiteMatch(match[next]))
        {
            match[next] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int next;
            cin >> next;
            graph[i].push_back(next);
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        visitedCnt++;
        if (bipartiteMatch(i))
            answer++;
    }
    int second = 0;
    for (int i = 1; i <= n; i++)
    {
        visitedCnt++;
        if (bipartiteMatch(i))
            second++;
    }
    if (second > k)
        second = k;
    cout << answer + second;
}