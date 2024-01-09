#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[200001];

int main()
{
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    priority_queue<int> pq;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
}