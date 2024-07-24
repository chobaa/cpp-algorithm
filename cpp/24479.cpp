#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> road[100001];
int cnt[100001];

int n, m, r, idx = 1;

void dfs(int cur)
{
    cnt[cur] = idx++;
    for (int i = 0; i < road[cur].size(); i++)
    {
        int next = road[cur][i];
        if (cnt[next] == 0)
        {
            dfs(next);
        }
    }
}

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(road[i].begin(), road[i].end());
    }
    dfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i] << "\n";
    }
}