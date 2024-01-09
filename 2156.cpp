#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> dp;

int main()
{
    int n;
    cin >> n;
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = max({dp[i - 2] + dp[i], dp[i - 1] + dp[i], dp[i - 2] + dp[i - 1]});
    }
    cout << dp[n - 1];
}