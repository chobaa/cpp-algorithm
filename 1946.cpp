#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v1;
        int n, answer;
        cin >> n;
        answer = n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v1.push_back({a, b});
        }
        sort(v1.begin(), v1.end());
        int top = v1[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v1[i].second > top)
            {
                answer--;
            }
            top = min(top, v1[i].second);
        }
        cout << answer << "\n";
    }
}