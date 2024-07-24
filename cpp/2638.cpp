#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map(101, vector<int>(101));
vector<vector<int>> outer_map(101, vector<int>(101));

void inner_outer_air()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    outer_map[0][0] = 1;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int t = 0; t < 4; t++)
        {
            int next_i = i + dy[t];
            int next_j = j + dx[t];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
                continue;
            else if (outer_map[next_i][next_j] == 0)
            {
                outer_map[next_i][next_j] = 1;
                q.push({next_i, next_j});
            }
        }
    }
}

int main()
{
    queue<pair<int, int>> q;
    int count = 0, answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                outer_map[i][j] = -1;
                count++;
            }
        }
    }
    inner_outer_air();
    while (count)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1)
                {
                    int check = 0;
                    for (int t = 0; t < 4; t++)
                    {
                        int next_i = i + dy[t];
                        int next_j = j + dx[t];
                        if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
                            continue;
                        else if (map[next_i][next_j] == 0 && outer_map[next_i][next_j] == 1)
                            check++;
                    }
                    if (check >= 2)
                    {
                        q.push({i, j});
                        count--;
                    }
                }
            }
        }
        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            map[y][x] = 0;
            outer_map[y][x] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (outer_map[i][j] == 1)
                    outer_map[i][j] = 0;
            }
        }
        inner_outer_air();
        answer++;
    }
    cout << answer;
}