#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    string str;
    cin >> str;
    set<string> s;
    for (int t = 1; t <= str.size(); t++)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (t + i > str.size())
                break;
            s.insert(str.substr(i, t));
        }
    }
    cout << s.size();
}