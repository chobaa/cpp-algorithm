#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> list[100001];
int weight[100001];

void dfs(int cur)
{
    for (int i = 0; i < list[cur].size(); i++)
    {
        int next = list[cur][i];
        weight[next] += weight[cur];
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == -1)
            continue;
        list[temp].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        weight[a] += b;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << weight[i] << " ";
    }
}