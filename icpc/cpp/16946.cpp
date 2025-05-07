#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int n, m, nbr = 1;
int map[1001][1001];
int cnt[1001][1001];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<int> numbering;

void bfs(int y, int x)
{
    int total = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    cnt[y][x] = nbr;
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
            if (map[ny][nx] == 0 && cnt[ny][nx] == 0)
            {
                cnt[ny][nx] = nbr;
                total += 1;
                q.push({ny, nx});
            }
        }
    }
    numbering.push_back(total);
    nbr++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }
    numbering.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && cnt[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                for (int t = 0; t < 4; t++)
                {
                    int ny = i + dy[t];
                    int nx = j + dx[t];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    s.insert(cnt[ny][nx]);
                }
                for (auto a : s)
                {
                    map[i][j] += numbering[a];
                }
                s.clear();
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] % 10;
        }
        cout << "\n";
    }
}