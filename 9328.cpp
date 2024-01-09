#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool key[26];

char map[111][111];
bool visited[111][111];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int t, n, m, answer = 0;

void initialize()
{
    for (int i = 0; i < 111; i++)
    {
        for (int j = 0; j < 111; j++)
        {
            visited[i][j] = false;
            map[i][j] = '.';
        }
    }
    for (int i = 0; i < 26; i++)
    {
        key[i] = false;
    }
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];
    q.push({y, x});
    visited[y][x] = true;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny > n + 1 || nx < 0 || nx > m + 1)
                continue;
            if (!visited[ny][nx] && map[ny][nx] == '.')
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else if (!visited[ny][nx] && map[ny][nx] == '$')
            {
                answer++;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else if (!visited[ny][nx] && map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
            {
                visited[ny][nx] = true;
                key[map[ny][nx] - 'a'] = true;
                while (!door[map[ny][nx] - 'a'].empty())
                {
                    q.push(door[map[ny][nx] - 'a'].front());
                    door[map[ny][nx] - 'a'].pop();
                }
                q.push({ny, nx});
            }
            else if (!visited[ny][nx] && map[ny][nx] >= 'A' && map[ny][nx] <= 'Z')
            {
                if (key[map[ny][nx] - 'A'])
                {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                else
                {
                    door[map[ny][nx] - 'A'].push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        answer = 0;
        cin >> n >> m;
        initialize();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
            }
        }
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                break;
            else
                key[s[i] - 'a'] = true;
        }
        bfs(0, 0);
        cout << answer << "\n";
    }
}