#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;

long long stick[1000001];
long long ans = 0;

int main()
{
    cin >> n >> k;
    long long start = 1, end = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> stick[i];
        end = max(end, stick[i]);
    }
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for (long long i = 0; i < n; i++)
        {
            cnt += stick[i] / mid;
        }
        if (cnt >= k)
        {
            start = mid + 1;
            ans = max(ans, mid);
        }
        else
            end = mid - 1;
    }
    cout << ans;
}