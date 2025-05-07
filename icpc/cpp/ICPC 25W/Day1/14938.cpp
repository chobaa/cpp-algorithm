#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int dp[101][101];
int score[101];
int n, m, r, answer;

int main()
{
    cin >> n >> m >> r;
    // init to inf
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
        dp[i][i] = 0;
    }
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
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
    for (int start = 1; start <= n; start++)
    {
        int temp = 0;
        for (int dest = 1; dest <= n; dest++)
        {
            if (dp[start][dest] <= m)
                temp += score[dest];
        }
        answer = max(answer, temp);
    }
    cout << answer;
}