#include <iostream>
#include <vector>

using namespace std;

int n, m;

char map[21][21];

bool visited[27];

int answer = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x, int count)
{
    answer = max(answer, count);
    for (int i = 0; i < 4; i++)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
            continue;
        else if (!visited[map[next_y][next_x] - 'A'])
        {
            visited[map[next_y][next_x] - 'A'] = true;
            dfs(next_y, next_x, count + 1);
            visited[map[next_y][next_x] - 'A'] = false;
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
        }
    }
    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer;
}