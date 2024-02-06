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
                                q.push({i, j});
                                sum += population[i][j];
                            }
                            if (!check[ny][nx])
                            {
                                check[ny][nx] = true;
                                q.push({ny, nx});
                                sum += population[ny][nx];
                            }
                        }
                    }
                }
            }
        }
        if (q.size() == 0)
            break;
        int temp = sum / q.size();
        while (!q.empty())
        {
            int cy = q.front().first;
            int cx = q.front().second;
            population[cy][cx] = temp;
            check[cy][cx] = false;
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