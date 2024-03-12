#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n, m;
    int crane_idx = 0;
    bool possible = true;
    int total = 0;
    int cnt = 0;
    vector<int> crane;
    vector<int> box;
    map<int, int> hash;
    cin >> n;
    int crane_top = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        crane.push_back(temp);
        crane_top = max(crane_top, temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        box.push_back(temp);
        if (crane_top < temp)
        {
            possible = false;
            cnt = -1;
        }
    }
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    for (int i = 0; i < m; i++)
    {
        if (crane_idx == n)
            break;
        if (crane[crane_idx] < box[i])
        {
            hash[crane_idx] = i - 1;
            crane_idx++;
            i--;
        }
    }
    if (crane_idx != n)
    {
        while (crane_idx < n)
        {
            hash[crane_idx] = m - 1;
            crane_idx++;
        }
    }
    if (possible)
    {
        while (total < m)
        {
            for (int i = 0; i < n; i++)
            {
                int cur_idx = hash[i];
                while (cur_idx >= 0 && box[cur_idx] == -1)
                {
                    cur_idx--;
                }
                if (cur_idx >= 0)
                {
                    total++;
                    box[cur_idx] = -1;
                    hash[i] = cur_idx - 1;
                }
            }
            cnt++;
        }
    }
    cout << cnt;
}