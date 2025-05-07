#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    long long answer = arr[0] * arr[0];
    for (int i = 1; i < n; i++)
    {
        answer = answer ^ (arr[i] * arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        answer = answer ^ (arr[i] * arr[i + 1]);
    }
    cout << answer;
}