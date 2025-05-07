#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;

int dp[1001][1001];

int main()
{
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int max_y = s1.size();
    int max_x = s2.size();

    string answer;
    cout << dp[max_y][max_x] << "\n";

    while (dp[max_y][max_x])
    {
        if (dp[max_y][max_x] == dp[max_y - 1][max_x])
        {
            max_y--;
        }
        else if (dp[max_y][max_x] == dp[max_y][max_x - 1])
        {
            max_x--;
        }
        else
        {
            answer = s1[max_y-1] + answer;
            max_y--;
            max_x--;
        }
    }
    cout << answer;
}