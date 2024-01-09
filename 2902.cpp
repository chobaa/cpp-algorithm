#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string answer;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            answer += str[i];
    }
    cout << answer;
}