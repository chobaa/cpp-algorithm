#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[51];

int main()
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 51; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[50];
}