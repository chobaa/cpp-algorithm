#include <iostream>
#include <algorithm>

using namespace std;

int oper[4];

int n, top = -1e9, bottom = 1e9;

int arr[12];

void dfs(int cnt, int total)
{
    if (cnt == n)
    {
        top = max(top, total);
        bottom = min(bottom, total);
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (oper[i] > 0)
            {
                oper[i]--;
                if (i == 0)
                    dfs(cnt + 1, total + arr[cnt]);
                else if (i == 1)
                    dfs(cnt + 1, total - arr[cnt]);
                else if (i == 2)
                    dfs(cnt + 1, total * arr[cnt]);
                else if (i == 3)
                    dfs(cnt + 1, total / arr[cnt]);
                oper[i]++;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }
    dfs(1, arr[0]);

    cout << top << "\n"
         << bottom;
}