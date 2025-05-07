#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s1;
        cin >> s1;
        long long s = 0, l = 0, answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '-')
                s++;
            else
                l++;
        }
        if (n < 3 || s < 2 || l < 1)
            answer = 0;
        else
            answer = (s / 2) * (s / 2 + s % 2) * l;
        cout << answer << "\n";
    }
}