#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> list[11];
int people[11];
int team[11];
bool visited[11];
int n;
vector<bool> l;

void initialize()
{
    for (int i = 0; i < n; i++)
    {
        if (l[i] == true)
            team[i] = 1;
        else
            team[i] = 2;
        visited[i] = false;
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < list[cur].size(); i++)
        {
            int next = list[cur][i];
            if (!visited[next] && team[cur] == team[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    int answer = 9999999;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            list[i].push_back(temp - 1);
        }
    }
    int idx = 1;
    while (idx < n)
    {
        l.clear();
        for (int t = 0; t < idx; t++)
        {
            l.push_back(false);
        }
        for (int t = idx; t < n; t++)
        {
            l.push_back(true);
        }
        sort(l.begin(), l.end());
        do
        {
            initialize();
            int time = 0;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    bfs(i);
                    time++;
                }
            }
            if (time < 3)
            {
                int a = 0, b = 0;
                for (int i = 0; i < n; i++)
                {
                    if (team[i] == 1)
                        a += people[i];
                    else
                        b += people[i];
                }
                answer = min(answer, abs(b - a));
            }
        } while (next_permutation(l.begin(), l.end()));
        idx++;
    }
    if (answer == 9999999)
        cout << -1;
    else
        cout << answer;
}