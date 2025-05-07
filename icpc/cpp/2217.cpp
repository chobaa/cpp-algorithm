#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long total = arr[n - 1];
    answer = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        long long top = arr[i] * (n - i);
        if (answer < top)
            answer = top;
    }
    cout << answer;
}