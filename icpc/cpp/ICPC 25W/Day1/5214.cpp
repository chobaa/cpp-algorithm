#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, k, m;
vector<int> connected[100001];
vector<int> hyperloop[1001];
int cost[100001];

void bfs()
{
    queue<int> q;
    q.push(1);
    cost[1] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nextloop : connected[cur])
        {
            for (auto next : hyperloop[nextloop])
            {
                if (cost[next] == 0)
                {
                    cost[next] = cost[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            hyperloop[i].push_back(a);
            connected[a].push_back(i);
        }
    }
    bfs();
    if (cost[n] == 0)
        cout << -1;
    else
        cout << cost[n];
}