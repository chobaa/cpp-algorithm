#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string temp;
        cin >> temp;
        if (regex_match(temp, regex("(100+1+|01)+")))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
