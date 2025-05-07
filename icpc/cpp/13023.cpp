#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> node[2000];
bool visited[2001];
int n, m;
int answer = 0;

void dfs(int cur, int cnt)
{
    if (cnt == 4)
    {
        answer = 1;
        return;
    }
    for (int i = 0; i < node[cur].size(); i++)
    {
        int next = node[cur][i];
        if (!visited[next])
        {
            visited[next] = true;
            dfs(next, cnt + 1);
            visited[next] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (answer == 1)
            break;
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }
    cout << answer << "\n";
}