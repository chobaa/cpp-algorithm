#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> arr;
vector<long long> result;

int main()
{
    cin >> n;
    arr.resize(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long answer = 1e18;
    result.resize(3);
    for (long long k = 0; k < n - 2; k++)
    {
        long long start = k + 1;
        long long end = n - 1;
        while (start < end)
        {
            long long cur = arr[k] + arr[start] + arr[end];
            if (abs(answer) > abs(cur))
            {
                answer = cur;
                result[0] = arr[start];
                result[1] = arr[k];
                result[2] = arr[end];
            }
            if (cur < 0)
            {
                start++;
            }
            else
                end--;
        }
    }
    sort(result.begin(), result.end());
    cout << result[0] << " " << result[1] << " " << result[2];
}