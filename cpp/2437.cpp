#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (sum + 1 >= arr[i])
        {
            sum += arr[i];
        }
        else
            break;
    }
    cout << sum + 1;
}