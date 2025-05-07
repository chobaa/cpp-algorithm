#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[6];
    int list[3];
    long long n;
    cin >> n;
    long long answer = 0;
    int cur_max = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        answer += arr[i];
        cur_max = max(arr[i], cur_max);
    }
    if (n == 1)
        cout << answer - cur_max;
    else
    {
        answer = 0;
        list[0] = min(arr[0], arr[5]);
        list[1] = min(arr[1], arr[4]);
        list[2] = min(arr[2], arr[3]);

        sort(list, list + 3);

        int s1 = list[0];
        int s2 = list[1] + s1;
        int s3 = list[2] + s2;

        answer += s3 * 4;
        answer += s2 * ((n - 1) * 4 + 4 * (n - 2));
        answer += s1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));

        cout << answer;
    }
}