#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cost[1001][3];
    int dp[1001][3];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    int answer = 987654321;
    memset(dp, 0, sizeof(dp));
    for (int rgb = 0; rgb < 3; rgb++)
    {
        for (int t = 0; t < 3; t++)
        {
            if (rgb == t)
            {
                dp[1][rgb] = cost[1][rgb];
            }
            else
                dp[1][t] = 987654321;
        }
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }
        for (int t = 0; t < 3; t++)
        {
            if (rgb == t)
            {
                continue;
            }
            else
                answer = min(answer, dp[n][t]);
        }
    }
    cout << answer;
}