#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int candy[30001];
int parent[30001];
int person[30001];
int dp[3010];

int get_parent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y)
{
    x = get_parent(x);
    y = get_parent(y);
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> candy[i];
        parent[i] = i;
        person[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_parent(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != i)
        {
            int p = get_parent(i);
            candy[p] += candy[i];
            person[p] += person[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != i)
            continue;
        for (int j = k - 1; j - person[i] >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j - person[i]] + candy[i]);
        }
    }
    cout << dp[k - 1];
}