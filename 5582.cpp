#include <iostream>
#include <string>
#include <algorithm>

int dp[4001][4001];
using namespace std;

int main()
{
    int answer = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                answer = max(answer, dp[i + 1][j + 1]);
            }
        }
    }
    cout << answer;
}