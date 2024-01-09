#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, upper = 0, lower = 0, answer = 0;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (upper < a)
            upper = a + 1;
        pq.push({b, a});
    }
    for (int i = 0; i < upper; i++)
    {
        arr[i] = 0;
    }
    while (!pq.empty())
    {
        int idx = pq.top().second;
        for (int i = idx; i > 0; i--)
        {
            if (arr[i] == 0)
            {
                arr[i] = pq.top().first;
                answer += arr[i];
                break;
            }
        }
        pq.pop();
    }
    cout << answer;
}