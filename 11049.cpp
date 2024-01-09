#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int row[501];
int col[501];
int dp[501][501];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> row[i] >> col[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + i >= n)
                break;
            int result = 987654321;
            for (int t = j; t < j + i; t++)
            {
                result = min(dp[j][t] + dp[t + 1][j + i] + row[j] * col[t] * col[j + i], result);
            }
            dp[j][j + i] = result;
        }
    }
    cout << dp[0][n - 1];
}