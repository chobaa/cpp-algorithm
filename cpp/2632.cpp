#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n, a, b;
vector<int> p1;
vector<int> p2;
vector<int> v1;
vector<int> v2;

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int temp;
        cin >> temp;
        p1.push_back(temp);
    }
    for (int i = 0; i < a; i++)
    {
        int idx = i;
        int total = 0;
        for (int j = 1; j < a; j++)
        {
            total += p1[idx];
            v1.push_back(total);
            idx = (idx + 1) % a;
        }
    }
    for (int i = 0; i < b; i++)
    {
        int temp;
        cin >> temp;
        p2.push_back(temp);
    }
    for (int i = 0; i < b; i++)
    {
        int idx = i;
        int total = 0;
        for (int j = 1; j < b; j++)
        {
            total += p2[idx];
            v2.push_back(total);
            idx = (idx + 1) % b;
        }
    }
    v1.push_back(accumulate(p1.begin(), p1.end(), 0));
    v2.push_back(accumulate(p2.begin(), p2.end(), 0));
    v1.push_back(0);
    v2.push_back(0);
    sort(v2.begin(), v2.end());
    int answer = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int diff = n - v1[i];
        if (diff < 0)
            continue;
        int hi = upper_bound(v2.begin(), v2.end(), diff) - v2.begin();
        int lo = lower_bound(v2.begin(), v2.end(), diff) - v2.begin();
        answer += hi - lo;
    }
    cout << answer;
}