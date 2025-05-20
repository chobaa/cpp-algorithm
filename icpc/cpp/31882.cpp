#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long answer = 0;
int cnt[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cur = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '2')
        {
            cur += 1;
            cnt[cur] += 1;
        }
        else
            cur = 0;
    }
    for (int i = n; i > 0; i--)
    {
        if (cnt[i] != 0)
        {
            answer += (long long)i * cnt[i];
            cnt[i - 1] += cnt[i];
        }
    }
    cout << answer;
}