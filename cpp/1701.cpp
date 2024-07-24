#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int result = 0;

string str;

int fail[5001];

void kmp(string pattern)
{
    for (int i = 0; i < pattern.size(); i++)
    {
        fail[i] = 0;
    }
    int j = 0;
    for (int i = 1; i < pattern.size(); i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
        if (result < fail[i])
            result = fail[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        kmp(str.substr(i));
    }
    cout << result;
}