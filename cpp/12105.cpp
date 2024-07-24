#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
vector<int> answer;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    answer.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (answer.back() >= arr[i])
        {
            auto idx = lower_bound(answer.begin(), answer.end(), arr[i]);
            *idx = arr[i];
        }
        else
            answer.push_back(arr[i]);
    }

    cout << answer.size();
}