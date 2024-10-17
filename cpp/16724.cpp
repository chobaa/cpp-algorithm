#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char map[1001][1001];
int check[1001][1001];
int answer = 0;

void find_path(int y, int x)
{
    if (map[y][x] == 'D')
    {
        if (y + 1 >= n || check[y + 1][x] == -1)
        {
            answer++;
            return;
        }
        if (check[y + 1][x] == 0)
        {
            check[y + 1][x] = -1;
            find_path(y + 1, x);
            check[y + 1][x] = 1;
        }
        else
        {
            return;
        }
    }
    else if (map[y][x] == 'U')
    {
        if (y - 1 < 0 || check[y - 1][x] == -1)
        {
            answer++;
            return;
        }
        if (check[y - 1][x] == 0)
        {
            check[y - 1][x] = -1;
            find_path(y - 1, x);
            check[y - 1][x] = 1;
        }
        else
        {
            return;
        }
    }
    else if (map[y][x] == 'R')
    {
        if (x + 1 >= m || check[y][x + 1] == -1)
        {
            answer++;
            return;
        }
        if (check[y][x + 1] == 0)
        {
            check[y][x + 1] = -1;
            find_path(y, x + 1);
            check[y][x + 1] = 1;
        }
        else
        {
            return;
        }
    }
    else if (map[y][x] == 'L')
    {
        if (x - 1 < 0 || check[y][x - 1] == -1)
        {
            answer++;
            return;
        }
        if (check[y][x - 1] == 0)
        {
            check[y][x - 1] = -1;
            find_path(y, x - 1);
            check[y][x - 1] = 1;
        }
        else
        {
            return;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] == 0)
            {
                check[i][j] = -1;
                find_path(i, j);
                check[i][j] = 1;
            }
        }
    }
    cout << answer;
}