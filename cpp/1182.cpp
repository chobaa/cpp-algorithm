#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, s;
int arr[21];
int answer = 0;

void find_sum(int idx, int sum)
{
    if (idx == n)
        return;
    if (sum + arr[idx] == s)
    {
        answer++;
    }
    find_sum(idx + 1, sum);
    find_sum(idx + 1, sum + arr[idx]);
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    find_sum(0, 0);
    cout << answer;
}