#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> stock;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            stock.push_back(temp);
            pq.push({temp, i});
        }
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (pq.top().second > i)
            {
                answer += pq.top().first - stock[i];
            }
            else
            {
                if (i != pq.top().second)
                    i--;
                pq.pop();
            }
            if (pq.empty())
                break;
        }
        cout << answer << "\n";
    }
}