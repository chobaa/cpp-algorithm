#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int coin[101];

int n, k;
long long dp[10001];
long long answer = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
}