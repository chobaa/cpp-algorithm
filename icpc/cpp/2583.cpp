#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

bool field[101][101];
vector<int> area;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs(int y, int x)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    field[y][x] = true;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (!field[ny][nx])
            {
                field[ny][nx] = true;
                cnt++;
                q.push({ny, nx});
            }
        }
    }
    area.push_back(cnt);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                field[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!field[i][j])
            {
                bfs(i, j);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << area.size() << "\n";
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }
}