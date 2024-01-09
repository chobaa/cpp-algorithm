#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int target;
    cin >> target;
    sort(v.begin(), v.end());
    int start = 1;
    int end = v.back();
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= mid)
                total += v[i];
            else
                total += mid;
        }
        if (total <= target)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << answer;
}