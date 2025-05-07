#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int map[51][51];

bool check[51][51];

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};

void dfs(int y, int x)
{
    check[y][x] = true;
    for (int i = 0; i < 8; i++)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
            continue;
        if (map[next_y][next_x] == 1 && !check[next_y][next_x])
        {
            dfs(next_y, next_x);
        }
    }
}

int main()
{
    while (1)
    {
        cin >> m >> n;
        int answer = 0;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
                check[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!check[i][j] && map[i][j] == 1)
                {
                    dfs(i, j);
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
}