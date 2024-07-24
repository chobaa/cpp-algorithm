#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int degree[1002] = {
    0,
};
vector<int> list[1002];
vector<int> answer;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vector<int> v;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
            for (int i = 0; i < v.size() - 1; i++)
            {
                list[v[i]].push_back(temp);
                degree[temp]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for (int j = 0; j < list[cur].size(); j++)
        {
            degree[list[cur][j]]--;
            if (degree[list[cur][j]] == 0)
            {
                q.push(list[cur][j]);
            }
        }
    }
    if (answer.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << answer[i] << "\n";
        }
    }
    else
        cout << 0 << "\n";
}