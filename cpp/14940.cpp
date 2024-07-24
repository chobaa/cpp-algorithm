#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int result[1001][1001];
int start_i, start_j, n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    result[start_i][start_j] = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if (arr[next_y][next_x] == 0)
                continue;
            if (result[next_y][next_x] != -1)
                continue;
            q.push({next_y, next_x});
            result[next_y][next_x] = result[y][x] + 1;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            result[i][j] = -1;
            if (arr[i][j] == 2)
            {
                start_i = i;
                start_j = j;
            }
            else if (arr[i][j] == 0)
            {
                result[i][j] = 0;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}