#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
set<int> s;
vector<int> v, arr;

int main()
{
    int n, k, answer = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (s.find(temp) == s.end())
        {
            s.insert(temp);
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
    {
        arr.push_back(v[i] - v[i - 1]);
    }
    sort(arr.begin(), arr.end());
    if (k > arr.size())
        cout << 0 << "\n";
    else
    {
        for (int i = 0; i < arr.size() - k + 1; i++)
        {
            answer += arr[i];
        }
        cout << answer;
    }
}