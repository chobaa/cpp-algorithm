#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp.length() < 6)
            continue;
        if (temp.substr(temp.length() - 6) == "Cheese")
            s.insert(temp);
    }
    if (s.size() >= 4)
        cout << "yummy\n";
    else
        cout << "sad\n";
}