#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> time;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        time.push_back({a * 100 + b, c * 100 + d});
    }
    sort(time.begin(), time.end());
    int before_max = 301;
    int before_min = 0;
    int cur_max = 0;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (time[i].first > before_min && time[i].first <= before_max)
        {
            if (cur_max < time[i].second)
            {
                cur_max = time[i].second;
            }
            if (time[i].second >= 1201)
            {
                answer++;
                before_max = cur_max;
                break;
            }
        }
        else
        {
            if (before_max >= cur_max)
            {
                break;
            }
            answer++;
            before_min = before_max;
            before_max = cur_max;
            i--;
        }
    }
    if (before_max >= 1201)
    {
        cout << answer;
    }
    else
        cout << 0;
}