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
        priority_queue<int, vector<int>, greater<int>> pq;
        int n;
        cin >> n;
        vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            pq.push(temp);
            if (i % 2 == 0)
            {
                vector<int> v;
                for (int j = 0; j < i / 2; j++)
                {
                    v.push_back(pq.top());
                    pq.pop();
                }
                answer.push_back(pq.top());
                for (int j = 0; j < i / 2; j++)
                {
                    pq.push(v[j]);
                }
                v.clear();
            }
        }
        cout << answer.size() << "\n";
        for (int i = 0; i < answer.size(); i++)
        {
            if (i != 0 && i % 10 == 0)
                cout << "\n";
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
}