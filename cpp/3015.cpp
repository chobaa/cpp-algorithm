#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<pair<int, int>> s;

int main()
{
    long long n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int cnt = 1;
        while (!s.empty() && s.top().first <= x)
        {
            answer += s.top().second;
            if (s.top().first == x)
                cnt += s.top().second;
            s.pop();
        }
        if (!s.empty())
        {
            answer++;
        }
        s.push({x, cnt});
    }
    cout << answer;
}