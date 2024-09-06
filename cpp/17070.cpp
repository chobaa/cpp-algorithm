#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, answer = 0;
int map[17][17];

void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 0});
    while (!q.empty())
    {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cs = q.front().second;
        q.pop();
        if (cy == n - 1 && cx == n - 1)
        {
            answer++;
            continue;
        }
        int check = 0;
        if (cx + 1 < n && map[cy][cx + 1] == 0)
        {
            if (cs == 0 || cs == 2)
                q.push({{cy, cx + 1}, 0});
            check++;
        }
        if (cy + 1 < n && map[cy + 1][cx] == 0)
        {
            if (cs == 1 || cs == 2)
                q.push({{cy + 1, cx}, 1});
            check++;
        }
        if (check == 2 && map[cy + 1][cx + 1] == 0)
        {
            q.push({{cy + 1, cx + 1}, 2});
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    bfs();
    cout << answer;
}