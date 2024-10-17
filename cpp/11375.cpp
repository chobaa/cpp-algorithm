#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<int> v[1001];
bool visited[1001];
int work[1001];
int answer = 0;

bool dfs(int a)
{
    visited[a] = true;
    for (int i = 0; i < v[a].size(); i++)
    {
        int b = v[a][i];
        if (work[b] == 0 || !visited[work[b]] && dfs(work[b]))
        {
            work[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            answer++;
    }
    cout << answer;
}