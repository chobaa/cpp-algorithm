#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }
    long long answer = 0;
    while(pq.size() != 1){
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        answer += a + b;
        pq.push(-(a+b));
    }
    if(n==1) cout << 0;
    else cout << answer;
}