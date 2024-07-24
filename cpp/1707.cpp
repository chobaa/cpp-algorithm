#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> graph[20001];
int paint[20001];
bool answer = true;

void bfs(int x)
{
    queue<pair<int, int>> q;
    q.push({x, 1});
    paint[x] = 1;
    while (!q.empty())
    {
        int cur = q.front().first;
        int color = q.front().second;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (paint[next] == 0)
            {
                paint[next] = color * -1;
                q.push({next, color * -1});
            }
            else if (paint[next] + color != 0)
            {
                answer = false;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(paint, 0, sizeof(paint));
        answer = true;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (paint[i] == 0)
            {
                bfs(i);
            }
        }
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
    }
}