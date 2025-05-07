#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int time[100001];

int main()
{
    unsigned long long n, m, answer = 1e9 * 1000000001;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    unsigned long long start = 0;
    unsigned long long end = 1e9 * 1000000001;
    sort(time, time + n);
    while (start <= end)
    {
        unsigned long long mid = (start + end) / 2;
        unsigned long long count = 0;
        for (int i = 0; i < n; i++)
        {
            count += mid / time[i];
        }
        if (count >= m)
        {
            answer = min(answer, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << answer;
}