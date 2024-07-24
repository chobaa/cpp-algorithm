#include <iostream>
#include <algorithm>
#include <queue>

char map[601][601];
bool visited[601][601];

using namespace std;
int n_start, m_start, n, m, result = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({n_start, m_start});
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x > m || next_y < 0 || next_y > n)
                continue;
            if (map[next_y][next_x] == 'O' && !visited[next_y][next_x])
            {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
            else if (map[next_y][next_x] == 'P' && !visited[next_y][next_x])
            {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
                result++;
            }
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
            cin >> map[i][j];
            if (map[i][j] == 'I')
            {
                n_start = i;
                m_start = j;
            }
        }
    }
    bfs();
    if (result == 0)
        cout << "TT";
    else
        cout << result;
}