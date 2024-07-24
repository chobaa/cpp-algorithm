#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
vector<int> shoot;

int main()
{
    int m, n, l;
    cin >> m >> n >> l;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        shoot.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int y, x;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(shoot.begin(), shoot.end());
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = m - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (abs(shoot[mid] - arr[i].first) + arr[i].second <= l)
            {
                answer++;
                break;
            }
            else
            {
                if (shoot[mid] >= arr[i].first)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
    }
    cout << answer;
}