#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
pair<int, int> v[1001];
bool visited[1001];
int work[1001];

bool dfs(int from)
{
    visited[from] = true;
    for (int i = v[from].first; i <= v[from].second; i++)
    {
        if (i > n)
            return false;
        if (work[i] == 0 || !visited[work[i]] && dfs(work[i]))
        {
            work[i] = from;
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i < 1001; i++)
        {
            v[i].first = 1;
            v[i].second = 0;
            work[i] = 0;
        }
        int answer = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[i].first = a;
            v[i].second = b;
        }
        for (int i = 1; i <= m; i++)
        {
            memset(visited, false, sizeof(visited));
            if (dfs(i))
                answer++;
        }
        cout << answer << "\n";
    }
}