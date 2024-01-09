#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    string answer;
    cin >> str;
    int idx = 0;
    if (str[str.length() - 1] == 'A' || str.length() % 3 != 1)
        answer = "NP";
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (i == str.length() - 1)
            {
                break;
            }
            if (str[i] == 'P')
                idx++;
            else if (str[i] == 'A' && str[i + 1] == 'P' && idx >= 2)
            {
                idx -= 2;
            }
            else
            {
                answer = "NP";
                break;
            }
        }
    }
    if (answer != "NP" && idx == 0)
        answer = "PPAP";
    else
        answer = "NP";
    cout << answer;
}