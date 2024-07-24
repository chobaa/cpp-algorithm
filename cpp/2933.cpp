#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, n;
char cave[101][101];
bool direction = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> cluster;

void throw_stick(int h)
{
    if (direction)
    {
        for (int i = 0; i < c; i++)
        {
            if (cave[h][i] == 'x')
            {
                cave[h][i] = '.';
                return;
            }
        }
    }
    else
    {
        for (int i = c - 1; i >= 0; i--)
        {
            if (cave[h][i] == 'x')
            {
                cave[h][i] = '.';
                return;
            }
        }
    }
}

void check_cluster()
{
    vector<vector<bool>> check(r + 1, vector<bool>(c + 1, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (cave[i][j] == '.' && !check[i][j])
            {
                int lowest = bfs(check, i, j);
                cluster.push_back({i, lowest});
            }
        }
    }
    if (cluster.size() > 1)
    {
        for (int i = 0; i < cluster.size(); i++)
        {
            if (cluster[i].second != r - 1)
            {
                move_cluster(cluster[i]);
                break;
            }
        }
    }
    cluster.clear();
    return;
}

int bfs(vector<vector<bool>> check, int y, int x)
{
    int lowest = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    check[y][x] = true;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            if (cave[ny][nx] == '.' && !check[ny][nx])
            {
                if (lowest < ny)
                    lowest = ny;
                check[ny][nx] = false;
                q.push({ny, nx});
            }
        }
    }
}

void move_cluster(pair<int, int> range)
{
    while (1)
    {
        for (int i = range.second; i >= range.first; i--)
        {
            if (i + 1 > r)
            {
                return;
            }
            for (int j = 0; j < c; j++)
            {
                if (cave[i][j] == 'x')
                {
                    if (cave[i + 1][j] == '.')
                    {
                        cave[i + 1][j] = 'x';
                        cave[i][j] = '.';
                    }
                    else
                    {
                        roll_back(range, {i, j - 1});
                        return;
                    }
                }
            }
        }
    }
}

void roll_back(pair<int, int> range, pair<int, int> hit_locate)
{
    for (int i = hit_locate.first; i <= range.second; i++)
    {
        if (i == hit_locate.first)
        {
            for (int j = hit_locate.second; j >= 0; j--)
            {
                cave[i][j] = cave[i + 1][j];
            }
        }
        else
        {
            for (int j = 0; j < c; j++)
            {
                cave[i][j] = cave[i + 1][j];
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> cave[i][j];
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        direction++;
        throw_stick(height);
        check_cluster();
    }
}