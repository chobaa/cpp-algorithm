#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long left = 0;
    long long right = n * n;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;
        for (int i = 1; i <= n; i++)
        {
            count += min(mid / i, n);
        }
        if (count < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << left;
}