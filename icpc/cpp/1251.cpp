#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    string answer = "{}";
    cin >> str;
    for (int i = 0; i < str.size() - 2; i++)
    {
        for (int j = i + 1; j < str.size() - 1; j++)
        {
            string temp;
            for (int t = i; t >= 0; t--)
            {
                temp += str[t];
            }
            for (int t = j; t > i; t--)
            {
                temp += str[t];
            }
            for (int t = str.size() - 1; t > j; t--)
            {
                temp += str[t];
            }
            if (answer > temp)
                answer = temp;
        }
    }
    cout << answer;
}