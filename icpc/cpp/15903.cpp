#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const long long a, const long long b)
    {
        return a > b;
    }
};

priority_queue<long long, vector<long long>, cmp> pq;

int main()
{
    long long n, m;
    long long answer = 0;
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        pq.push(temp);
    }
    for (long long i = 0; i < m; i++)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}