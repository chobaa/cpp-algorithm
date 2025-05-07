#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INIT pow(2, 18)

using namespace std;

int dp[200001][19];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][0];
    }
    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int cur = INIT;
        for (int j = 18; j >= 0; j--)
        {
            if (a == 0)
                break;
            if (a >= cur)
            {
                a -= cur;
                b = dp[b][j];
            }
            cur /= 2;
        }
        cout << b << "\n";
    }
}