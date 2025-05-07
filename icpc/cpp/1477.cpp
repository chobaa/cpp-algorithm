#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dist;
vector<int> list;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        dist.push_back(list[i] - prev);
        prev = list[i];
    }
    dist.push_back(l - prev);
    int start = 0, end = l;
    while (start + 1 < end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] % mid == 0)
            {
                cnt += dist[i] / mid - 1;
            }
            else
                cnt += dist[i] / mid;
        }
        if (cnt <= m)
        {
            end = mid;
        }
        else
            start = mid;
    }
    cout << end;
}