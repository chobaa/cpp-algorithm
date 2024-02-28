#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int day[100001];

int main()
{
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> day[i];
        sum += day[i];
    }
    int start = 1, end = sum;
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 1;
        int current = mid;
        bool pass = true;
        for (int i = 0; i < n; i++)
        {
            if (mid < day[i])
            {
                pass = false;   
                break;
            }
            if (current < day[i])
            {
                current = mid;
                cnt++;
            }
            current -= day[i];
        }
        if (cnt <= m && pass)
        {
            answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << answer;
}