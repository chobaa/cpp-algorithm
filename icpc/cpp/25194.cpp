#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int remain[7];
bool answer;

void dfs(int total)
{
    if (answer)
        return;
    if (total % 7 == 4)
    {
        answer = true;
        return;
    }
    for (int i = 1; i <= 6; i++)
    {
        if (remain[i] == 0)
            continue;
        remain[i]--;
        dfs(total + i);
        remain[i]++;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        remain[temp % 7]++;
    }
    dfs(0);
    if (answer)
        cout << "YES\n";
    else
        cout << "NO\n";
}