#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int idx = 0;

int main()
{
    string s;
    cin >> s;
    int k = 0, d = 0, a = 0;
    while (s[idx] != '/')
    {
        k *= 10;
        k += s[idx++] - '0';
    }
    idx++;
    while (s[idx] != '/')
    {
        d *= 10;
        d += s[idx++] - '0';
    }
    idx++;
    while (idx < s.length())
    {
        a *= 10;
        a += s[idx++] - '0';
    }
    if (k + a < d || d == 0)
        cout << "hasu";
    else
        cout << "gosu";
}