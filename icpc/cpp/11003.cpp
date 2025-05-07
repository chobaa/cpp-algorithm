#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int>> dq;
int list[5000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front().second + l == i)
            dq.pop_front();
        while (!dq.empty() && dq.back().first > list[i])
            dq.pop_back();
        dq.push_back({list[i], i});
        cout << dq.front().first << " ";
    }
}