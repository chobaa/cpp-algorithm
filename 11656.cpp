#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}