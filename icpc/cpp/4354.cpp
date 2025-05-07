#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
int table[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> s)
    {
        if (s[0] == '.')
            break;
        int n = s.length();
        memset(table,0,sizeof(table));
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
                j = table[j - 1];
            if (s[i] == s[j])
                table[i] = ++j;
        }
        int result = n - table[n - 1];
        if (n % result)
            cout << 1 << "\n";
        else
            cout << n / result << "\n";
    }
}