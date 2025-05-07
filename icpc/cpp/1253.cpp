#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            if (s == i)
            {
                s++;
                continue;
            }
            if (e == i)
            {
                e--;
                continue;
            }
            if (arr[s] + arr[e] == arr[i])
            {
                answer++;
                break;
            }
            if ((arr[s] + arr[e]) < arr[i])
            {
                s++;
            }
            else
                e--;
        }
    }
    cout << answer;
}