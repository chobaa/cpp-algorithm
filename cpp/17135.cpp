#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, ky, kx, kcnt, answer = 0;

int map[16][16];
int temp[16][16];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool check(int y, int x, int cnt)
{
    if (kcnt > cnt)
        return true;
    if (kcnt == cnt)
    {
        if (x < kx)
            return true;
    }
    return false;
}

bool check_finish()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 1)
                return false;
        }
    }
    return true;
}

void move_temp()
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = temp[i - 1][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        temp[0][j] = 0;
    }
}

void bfs(int shooter)
{
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({n - 1, shooter});
    cnt[n - 1][shooter] = 1;
    if (temp[n - 1][shooter] == 1)
    {
        ky = n - 1;
        kx = shooter;
        kcnt = 1;
        return;
    }
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cnt[cy][cx] == r)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (cnt[ny][nx] == 0)
            {
                cnt[ny][nx] = cnt[cy][cx] + 1;
                if (temp[ny][nx] == 1)
                {
                    if (check(ny, nx, cnt[ny][nx]))
                    {
                        ky = ny;
                        kx = nx;
                        kcnt = cnt[ny][nx];
                    }
                }
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    vector<bool> choose;
    for (int i = 0; i < m - 3; i++)
        choose.push_back(false);
    for (int i = 0; i < 3; i++)
        choose.push_back(true);
    do
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp[i][j] = map[i][j];
            }
        }
        vector<int> shoot;
        for (int i = 0; i < m; i++)
        {
            if (choose[i])
                shoot.push_back(i);
        }
        int total = 0;
        while (!check_finish())
        {
            vector<pair<int, int>> kill_list;
            for (int i = 0; i < 3; i++)
            {
                kcnt = 987654321;
                bfs(shoot[i]);
                if (kcnt == 987654321)
                    continue;
                kill_list.push_back({ky, kx});
            }
            for (int i = 0; i < kill_list.size(); i++)
            {
                int a = kill_list[i].first;
                int b = kill_list[i].second;
                if (temp[a][b] == 1)
                {
                    temp[a][b] = 0;
                    total++;
                }
            }
            move_temp();
        }
        answer = max(answer, total);
    } while (next_permutation(choose.begin(), choose.end()));
    cout << answer;
}