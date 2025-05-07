#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> arr;
long long answer = 2000000008, answer_low, answer_max;

void find_lowest(long long start, long long end)
{
    while (start < end)
    {
        long long target = arr[start] + arr[end];
        if (answer > abs(target))
        {
            answer = abs(target);
            answer_low = arr[start];
            answer_max = arr[end];
            if(answer == 0) break;
        }
        if (target < 0)
        {
            start++;
        }
        else
            end--;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    find_lowest(0, n - 1);
    cout << answer_low << " " << answer_max << "\n";
}