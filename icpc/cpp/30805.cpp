#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v1[101];
vector<int> v2[101];

int main()
{
    vector<int> answer;
    int n, m;
    int ans1 = -1, ans2 = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v1[temp].push_back(i);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        v2[temp].push_back(i);
    }
    for (int i = 100; i > 0; i--)
    {
        if (v1[i].empty() || v2[i].empty())
            continue;
        int idx1 = 0;
        int idx2 = 0;
        while (v1[i].size() > idx1 && ans1 >= v1[i][idx1])
            idx1++;
        if (v1[i].size() == idx1)
            continue;
        while (v2[i].size() > idx2 && ans2 >= v2[i][idx2])
            idx2++;
        if (v2[i].size() == idx2)
            continue;
        answer.push_back(i);
        ans1 = v1[i][idx1];
        ans2 = v2[i][idx2];
        i += 1;
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}