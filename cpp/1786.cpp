#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str, cmp;

int fail[1000001];
vector<int> answer;

void fail_func()
{
    for (int i = 1, j = 0; i < cmp.length(); i++)
    {
        while (j > 0 && cmp[i] != cmp[j])
            j = fail[j - 1];

        if (cmp[i] == cmp[j])
        {
            fail[i] = ++j;
        }
        else
        {
            fail[i] = 0;
        }
    }
}

void kmp()
{
    for (int i = 0, j = 0; i < str.length(); i++)
    {
        while (j > 0 && str[i] != cmp[j])
            j = fail[j - 1];

        if (str[i] == cmp[j])
        {
            if (j == cmp.length() - 1)
            {
                answer.push_back(i - j + 1);
                j = fail[j];
            }
            else
                j++;
        }
        else
            j = 0;
    }
}

int main()
{
    getline(cin, str);
    getline(cin, cmp);
    fail_func();
    kmp();
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
}