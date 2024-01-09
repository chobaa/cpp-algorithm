#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int bottom = v[0].first;
    int top = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (top >= v[i].first)
        {
            top = max(v[i].second, top);
            continue;
        }
        answer += top - bottom;
        top = v[i].second;
        bottom = v[i].first;
    }
    answer += top - bottom;
    cout << answer;
}