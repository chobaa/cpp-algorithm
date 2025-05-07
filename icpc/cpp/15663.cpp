#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int cnt[10001];
int arr[8];

void dfs(int total)
{
    if (total == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < 10001; i++)
        {
            if (cnt[i] > 0)
            {
                cnt[i]--;
                arr[total] = i;
                dfs(total + 1);
                cnt[i]++;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }
    dfs(0);
}