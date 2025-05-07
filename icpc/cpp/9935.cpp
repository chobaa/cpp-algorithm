#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2, s3;
    cin >> s1 >> s2;
    int len = s2.length();

    for (int i = 0; i < s1.length(); i++)
    {
        s3.push_back(s1[i]);
        if (s2.back() == s3.back())
        {
            for (int j = 1; j <= len; j++)
            {
                if (s2[len - j] != s3[s3.length() - j])
                {
                    break;
                }
                if (j == len)
                {
                    for (int t = 0; t < len; t++)
                    {
                        s3.pop_back();
                    }
                    break;
                }
            }
        }
    }

    if (s3.empty())
        cout << "FRULA";
    else
        cout << s3;
}