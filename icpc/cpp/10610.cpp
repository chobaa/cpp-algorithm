#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

string str, goal;

int main()
{
    cin >> str;
    cin >> goal;
    while (goal.size() > str.size())
    {
        if (goal.back() == 'A')
            goal.erase(goal.size() - 1);
        else if (goal.back() == 'B')
        {
            goal.erase(goal.size() - 1);
            reverse(goal.begin(), goal.end());
        }
        else
            break;
    }
    if (goal == str)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}