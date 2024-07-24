#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cnt[101];
vector<int> road[101];

int s, e;

void bfs()
{
    queue<int> q;
    q.push(s);
    cnt[s] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < road[cur].size(); i++)
        {
            int next = road[cur][i];
            if (cnt[next] == 0)
            {
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin >> s >> e;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    bfs();
    if (cnt[e] != 0)
        cout << cnt[e] - cnt[s];
    else
        cout << -1;
}