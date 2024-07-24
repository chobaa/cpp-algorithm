#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int n, k, answer = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    arr.push_back(0);
    sort(arr.begin(), arr.end());
    int first;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            first = i;
            break;
        }
    }
    for (int i = 0; i < first; i += k)
    {
        answer += abs(arr[i] * 2);
    }
    for (int i = n; i > first; i -= k)
    {
        answer += abs(arr[i] * 2);
    }
    answer -= max(abs(arr.front()), abs(arr.back()));
    cout << answer;
}