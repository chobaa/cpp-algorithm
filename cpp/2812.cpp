#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    string str, result;
    cin >> str;
    stack<char> s;
    stack<char> s2;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < str[i] && cnt < m)
        {
            s.pop();
            cnt++;
        }
        s.push({str[i]});
    }
    while (cnt < m)
    {
        cnt++;
        s.pop();
    }
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }
}