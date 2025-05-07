#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int v[501][2];
int dp[501][501];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            dp[j][i + j] = pow(2, 31) - 1;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + v[j][0] * v[k][1] * v[i + j][1]);
            }
        }
    }
    cout << dp[1][n];
}