#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k;

vector<vector<int>> pattern;
vector<vector<int>> pattern_rev;

vector<int> list[1001];

vector<vector<bool>> pass;
vector<vector<bool>> pass_rev;

bool output()
{
    for (int i = 0; i < pattern.size(); i++)
    {
        for (int t = 1; t <= n; t++)
        {
            if (t == n)
            {
                return true;
            }
            if (pass[i][t] || pass_rev[i][t])
                continue;
            else
                break;
        }
    }
    return false;
}

vector<int> get_pi(vector<int> pat)
{
    vector<int> fail(pat.size(), 0);
    int j = 0;
    for (int i = 1; i < pat.size(); i++)
    {
        while (j > 0 && pat[i] != pat[j])
            j = fail[j - 1];
        if (pat[i] == pat[j])
            fail[i] = ++j;
    }
    return fail;
}

bool kmp(vector<int> pat, vector<int> program)
{
    vector<int> fail;
    fail = get_pi(pat);
    int j = 0;
    for (int i = 0; i < program.size(); i++)
    {
        while (j > 0 && program[i] != pat[j])
            j = fail[j - 1];
        if (program[i] == pat[j])
        {
            j++;
            if (j == pat.size())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int num;
            cin >> num;
            list[i].push_back(num);
        }
    }
    pattern.resize(list[0].size() - k + 1);
    for (int i = 0; i < list[0].size() - k + 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            pattern[i].push_back(list[0][i + j]);
        }
    }
    for (int i = 0; i < list[0].size() - k + 1; i++)
    {
        vector<int> a = pattern[i];
        reverse(a.begin(), a.end());
        pattern_rev.push_back(a);
    }
    pass.resize(pattern.size(), vector<bool>(n, false));
    pass_rev.resize(pattern_rev.size(), vector<bool>(n, false));
    for (int t = 1; t < n; t++)
    {
        for (int i = 0; i < pattern.size(); i++)
        {
            if (kmp(pattern[i], list[t]))
                pass[i][t] = true;
        }
        for (int i = 0; i < pattern_rev.size(); i++)
        {
            if (kmp(pattern_rev[i], list[t]))
                pass_rev[i][t] = true;
        }
    }
    if (output())
        cout << "YES";
    else
        cout << "NO";
}