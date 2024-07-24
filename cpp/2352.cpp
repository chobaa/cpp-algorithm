#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[40001];

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (v.empty())
            v.push_back(temp);
        else
        {
            if (v.back() < temp)
                v.push_back(temp);
            else
            {
                auto pos = lower_bound(v.begin(), v.end(), temp);
                *pos = temp;
            }
        }
    }
    cout << v.size();
}