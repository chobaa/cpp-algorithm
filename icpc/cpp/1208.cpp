#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arr[41];
map<int, int> total;

long long n, s, cnt = 0;

void left_sum(int idx, int sum)
{
    if (idx == n / 2)
    {
        total[sum]++;
        return;
    }
    left_sum(idx + 1, sum);
    left_sum(idx + 1, sum + arr[idx]);
}

void right_sum(int idx, int sum)
{
    if (idx == n)
    {
        cnt += total[s - sum]++;
        return;
    }
    right_sum(idx + 1, sum);
    right_sum(idx + 1, sum + arr[idx]);
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    left_sum(0, 0);
    right_sum(n / 2, 0);

    if (!s)
        cout << cnt - 1;
    else
        cout << cnt;
}