#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long dp[31][31];
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][m];
}