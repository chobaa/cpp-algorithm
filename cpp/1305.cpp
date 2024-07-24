#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int result = 0;

int cnt[5001];

int l;
string str;

int fail[1000001];

void kmp()
{
    int j = 0;
    for (int i = 1; i < str.size(); i++)
    {
        while (j > 0 && str[i] != str[j])
            j = fail[j - 1];
        if (str[i] == str[j])
            fail[i] = ++j;
    }
}

int main()
{
    cin >> l;
    cin >> str;
    kmp();
    cout << l - fail[str.size() - 1];
}