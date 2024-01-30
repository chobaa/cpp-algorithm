#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 1)
            b.push_back(temp);
        else
            a.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int top = n, answer;
    for (int i = 1; i <= h; i++)
    {
        int cur = 0;
        auto pos = lower_bound(a.begin(), a.end(), i);
        cur += a.end() - pos;
        pos = lower_bound(b.begin(), b.end(), h - i + 1);
        cur += b.end() - pos;
        if (cur < top)
        {
            top = cur;
            answer = 1;
        }
        else if (cur == top)
        {
            answer++;
        }
    }
    cout << top << " " << answer;
}