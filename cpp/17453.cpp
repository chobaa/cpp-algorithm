#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

vector<vector<int>> sparse_table;

int n, m, max_log;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    max_log = log2(500000) + 1;
    sparse_table.resize(max_log + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> sparse_table[0][i];
    }
    for (int i = 1; i <= max_log; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = sparse_table[i - 1][j];
            sparse_table[i][j] = sparse_table[i - 1][tmp];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int value, cur;
        cin >> value >> cur;
        for (int i = 0; i < max_log; i++)
        {
            if (value & (1 << i))
                cur = sparse_table[i][cur];
        }
        cout << cur << "\n";
    }
}