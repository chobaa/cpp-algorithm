#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main()
{
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 1; j < b.size(); j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int col = a.size() - 1;
    int row = b.size() - 1;
    string result;
    cout << dp[col][row] << "\n";
    while (dp[col][row])
    {
        if (dp[col][row] == dp[col - 1][row])
            col--;
        else if (dp[col][row] == dp[col][row - 1])
            row--;
        else
        {
            result = a[col] + result;
            row--;
            col--;
        }
    }
    cout << result;
}