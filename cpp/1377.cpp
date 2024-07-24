#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, answer = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back({temp, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, v[i].second - i);
    }
    cout << answer + 1 << "\n";
}