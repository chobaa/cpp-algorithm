#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

int main()
{
    vector<int> wifi;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        wifi.push_back(temp);
    }
    sort(wifi.begin(), wifi.end());
    int minimum = -1;
    int left = 0;
    int right = wifi.back();
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int idx = 0, count = 1;
        for (int i = 1; i < n; i++)
        {
            if (wifi[i] - wifi[idx] >= mid)
            {
                idx = i;
                count++;
            }
        }
        if (count >= c)
        {
            left = mid + 1;
            minimum = mid;
        }
        else
            right = mid - 1;
    }
    cout << minimum;
}