#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, l, r;

int population[51][51];
bool check[51][51];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs(int y, int x)
{
    queue<pair<int, int>> bq;
    int cs = 0;
    bq.push({y, x});
    check[y][x] = false;
    while (!bq.empty())
    {
        int cy = bq.front().first;
        int cx = bq.front().second;
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (check[ny][nx])
            {
                q.push
            }
        }
    }
}

int main()
{
    cin >> n >> l >> r;
    int sum = 0, answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> population[i][j];
        }
    }
    while (1)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!check[i][j])
                {
                    for (int t = 0; t < 4; t++)
                    {
                        int ny = i + dy[t];
                        int nx = j + dx[t];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                            continue;
                        if (abs(population[i][j] - population[ny][nx]) >= l && abs(population[i][j] - population[ny][nx]) <= r)
                        {
                            if (!check[i][j])
                            {
                                check[i][j] = true;
                                sum++;
                            }
                            if (!check[ny][nx])
                            {
                                check[ny][nx] = true;
                                sum++;
                            }
                        }
                    }
                }
            }
        }
        if (q.size() == 0)
            break;
        while (!q.empty())
        {
            int cy = q.front().first;
            int cx = q.front().second;
            if (check[cy][cx])
                bfs(cy, cx);
            q.pop();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << population[i][j] << " ";
            }
            cout << "\n";
        }
        answer++;
    }
    cout << answer;
}