#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string a;
string b;
bool answer = false;

void dfs(string temp)
{
    if (temp.length() == a.length())
    {
        if (temp == a)
            answer = true;
        return;
    }
    else
    {
        if (temp.back() == 'A')
        {
            temp.pop_back();
            dfs(temp);
            temp.push_back('A');
        }
        if (temp.front() == 'B')
        {
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            dfs(temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    cin >> b;
    dfs(b);
    if (answer)
        cout << 1;
    else
        cout << 0;
}