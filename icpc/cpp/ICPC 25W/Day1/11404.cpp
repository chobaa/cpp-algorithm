#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, m;
int dp[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // init to inf
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    // init
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    // floyd-warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dp[i][j] == INF) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}