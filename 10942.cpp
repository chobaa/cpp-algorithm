#include <iostream>
#include <vector>

using namespace std;

int dp[2001][2001];
int num[2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i][i] = 1;
        if (i != 1 && num[i - 1] == num[i])
            dp[i - 1][i] = 1;
    }

    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (num[j] == num[i + j] && dp[j + 1][i + j - 1] == 1)
                dp[j][i + j] = 1;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}