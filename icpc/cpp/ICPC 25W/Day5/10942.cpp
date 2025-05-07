#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int arr[2001];
int dp[2001][2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int d = 2; d <= n; d++)
    {
        for (int s = 1; s + d <= n; s++)
        {
            if (arr[s] == arr[s + d] && dp[s + 1][s + d - 1])
                dp[s][s + d] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}