#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int dp[1001][2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    dp[0][0] = v[0].first;
    dp[0][1] = v[0].second;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + abs(v[i - 1].second - v[i].second), dp[i - 1][1] + abs(v[i - 1].first - v[i].second)) + v[i].first;
        dp[i][1] = max(dp[i - 1][0] + abs(v[i - 1].second - v[i].first), dp[i - 1][1] + abs(v[i - 1].first - v[i].first)) + v[i].second;
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}