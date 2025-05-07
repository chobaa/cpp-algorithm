#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char stu[25];

bool bfs(vector<int> temp)
{
    queue<int> q;
    bool visited[7];
    for (int i = 0; i < 7; i++)
    {
        visited[i] = false;
    }
    visited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int idx = q.front();
        int value = temp[idx];
        q.pop();
        for (int i = 0; i < 7; i++)
        {
            int nvalue = temp[i];
            int diff = abs(nvalue - value);
            if (!visited[i] && i != idx)
            {
                if ((nvalue / 5 == value / 5 && diff == 1) || diff == 5)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> stu[i * 5 + j];
        }
    }
    bool check[25];
    for (int i = 0; i < 25; i++)
    {
        if (i < 7)
            check[i] = true;
        else
            check[i] = false;
    }
    sort(check, check + 25);
    int answer = 0;
    do
    {
        vector<int> temp;
        for (int i = 0; i < 25; i++)
        {
            if (check[i])
                temp.push_back(i);
        }
        int cnt = 0;
        for (int i = 0; i < 7; i++)
        {
            if (stu[temp[i]] == 'S')
                cnt++;
        }
        if (cnt < 4)
            continue;
        if (bfs(temp))
            answer++;

    } while (next_permutation(check, check + 25));
    cout << answer;
}