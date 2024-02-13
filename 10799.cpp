#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int answer = 0;
    stack<char> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ')')
        {
            s.pop();
            if (str[i - 1] == '(')
                answer += s.size();
            else
                answer++;
        }
        else
            s.push(str[i]);
    }
    cout << answer;
}