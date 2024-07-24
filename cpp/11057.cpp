#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][10];

int main()
{
    int n, answer = 0;
    cin >> n;
    for (int i = 9; i >= 0; i--)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        answer = (dp[n][i] + answer) % 10007;
    }
    cout << answer;
}