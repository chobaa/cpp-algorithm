#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pqq;
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pqq.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        answer += pq.top() * pqq.top();
        pq.pop();
        pqq.pop();
    }
    cout << answer;
}