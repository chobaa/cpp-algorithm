#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[102][102][102];

int main()
{
    string str1, str2, str3, temp;
    cin >> str1 >> str2 >> str3;
    str1 = ' ' + str1;
    str2 = ' ' + str2;
    str3 = ' ' + str3;
    for (int i = 1; i < str1.size(); i++)
    {
        for (int j = 1; j < str2.size(); j++)
        {
            for (int t = 1; t < str3.size(); t++)
            {
                if (str1[i] == str2[j] && str2[j] == str3[t])
                    dp[i][j][t] = dp[i - 1][j - 1][t - 1] + 1;
                else
                    dp[i][j][t] = max(dp[i - 1][j][t], max(dp[i][j - 1][t], dp[i][j][t - 1]));
            }
        }
    }
    cout << dp[str1.size() - 1][str2.size() - 1][str3.size() - 1];
}