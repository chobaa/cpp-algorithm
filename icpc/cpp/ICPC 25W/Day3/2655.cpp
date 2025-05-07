#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, height;

int dp[101];
vector<tuple<int, int, int, int>> tower;
vector<int> answer;

bool cmp(tuple<int, int, int, int> v1, tuple<int, int, int, int> v2)
{
    return get<0>(v1) > get<0>(v2);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tower.push_back(make_tuple(a, b, c, i));
    }
    sort(tower.begin(), tower.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        dp[i] = get<1>(tower[i]);
        for (int j = 0; j < i; j++)
        {
            if (get<2>(tower[j]) > get<2>(tower[i]))
            {
                dp[i] = max(dp[i], dp[j] + get<1>(tower[i]));
            }
        }
        height = max(height, dp[i]);
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (dp[i] == height)
        {
            answer.push_back(get<3>(tower[i]));
            height -= get<1>(tower[i]);
        }
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
}