#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    long long int n, temp, answer = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    if (n == 1)
        answer = 0;
    else
    {
        while (pq.size() != 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            answer += first + second;
            pq.push(first + second);
        }
    }
    cout << answer;
}