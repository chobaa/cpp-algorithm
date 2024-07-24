#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;

ll n, c;
ll weight[31];
vector<ll> left_sum;
vector<ll> right_sum;

void left(ll cnt, ll sum)
{
    if (cnt == n / 2)
    {
        left_sum.push_back(sum);
        return;
    }
    left(cnt + 1, sum);
    left(cnt + 1, sum + weight[cnt]);
}

void right(ll cnt, ll sum)
{
    if (cnt == n)
    {
        right_sum.push_back(sum);
        return;
    }
    right(cnt + 1, sum);
    right(cnt + 1, sum + weight[cnt]);
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    left(0, 0);
    right(n / 2, 0);
    sort(right_sum.begin(), right_sum.end());
    ll answer = 0;
    for (int i = 0; i < left_sum.size(); i++)
    {
        answer += upper_bound(right_sum.begin(), right_sum.end(), c - left_sum[i]) - right_sum.begin();
    }
    cout << answer;
}