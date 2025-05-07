#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long n, m, answer = 0;
int map[301][301];
long long dp[301][301];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        map[y + 1][x + 1] = m - (x + y);
    }
    for (int i = 1; i < 301; i++)
    {
        for (int j = 1; j < 301; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + map[i][j];
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer;
}