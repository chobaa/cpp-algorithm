#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, endtime, answer = 0;
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= endtime)
        {
            answer++;
            endtime = v[i].first;
        }
    }
    cout << answer;
}