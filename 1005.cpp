#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t, n, k, w;

int main()
{
    cin >> t;
    while (t--)
    {
        int time[1002] = {
            0,
        };
        int degree[1002] = {
            0,
        };
        vector<int> dest[1002];
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> time[i];
        }
        for (int i = 0; i < k; i++)
        {
            int start, end;
            cin >> start >> end;
            dest[start].push_back(end);
            degree[end]++;
        }
        cin >> w;
        if (degree[w] == 0)
        {
            cout << time[w] << "\n";
            continue;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] == 0)
                pq.push({-time[i], i});
        }
        while (!pq.empty())
        {
            int t = -pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (int i = 0; i < dest[node].size(); i++)
            {
                degree[dest[node][i]]--;
                if (degree[dest[node][i]] == 0)
                {
                    if (dest[node][i] == w)
                    {
                        cout << t + time[dest[node][i]] << "\n";
                        break;
                    }
                    pq.push({-(t + time[dest[node][i]]), dest[node][i]});
                }
            }
        }
    }
}