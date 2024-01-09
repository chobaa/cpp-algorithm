#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char temp = s[0];
    int black = 0, white = 0;
    if (s[0] == '0')
        black++;
    else
        white++;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == temp)
            continue;
        else
        {
            if (s[i] == '0')
                black++;
            else
                white++;
            temp = s[i];
        }
    }
    cout << min(white, black);
}