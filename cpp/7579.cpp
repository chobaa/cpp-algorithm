#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][10001];

int main()
{
    int n, m;
    cin >> n >> m;
    int cost[101];
    int memory[101];
    for (int i = 1; i <= n; i++)
    {
        cin >> memory[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - cost[i] >= 0)
                dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i][j]);
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
}