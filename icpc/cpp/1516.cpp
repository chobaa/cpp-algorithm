#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int indegree[501];
int time[501];
int answer[501];
vector<int> link[501];

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] != -1)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> time[i];
        while (1)
        {
            int temp;
            cin >> temp;
            if (temp == -1)
                break;
            link[temp].push_back(i);
            indegree[i]++;
        }
    }
    while (!check())
    {
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                indegree[i] = -1;
                answer[i] += time[i];
                for (int j = 0; j < link[i].size(); j++)
                {
                    indegree[link[i][j]]--;
                    answer[link[i][j]] = max(answer[i], answer[link[i][j]]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << "\n";
    }
}