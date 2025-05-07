#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr1;
vector<long long> arr2;
long long v[4001][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1.push_back(v[i][0] + v[j][1]);
            arr2.push_back(v[i][2] + v[j][3]);
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    long long answer = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        int top = upper_bound(arr2.begin(), arr2.end(), -arr1[i]) - arr2.begin();
        int bottom = lower_bound(arr2.begin(), arr2.end(), -arr1[i]) - arr2.begin();
        answer += top - bottom;
    }
    cout << answer;
}