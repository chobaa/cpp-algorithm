#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10];
int paper[6];

int answer = 999999;

void makeup(int y, int x, int t, int v)
{
    for (int i = y; i < y + t; i++)
    {
        for (int j = x; j < x + t; j++)
        {
            map[i][j] = v;
        }
    }
    return;
}

bool fill_check()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool check(int y, int x, int t)
{
    for (int i = y; i < y + t; i++)
    {
        for (int j = x; j < x + t; j++)
        {
            if (map[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool range_check(int y, int x, int t)
{
    if (y + t > 10 || x + t > 10)
        return false;
    return true;
}

void dfs(int count)
{
    if (answer < count)
        return;
    if (fill_check())
    {
        if (answer > count)
            answer = count;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 1)
            {
                for (int t = 5; t > 0; t--)
                {
                    if (range_check(i, j, t) && paper[t] > 0 && check(i, j, t))
                    {
                        paper[t]--;
                        makeup(i, j, t, 0);
                        dfs(count + 1);
                        paper[t]++;
                        makeup(i, j, t, 1);
                    }
                }
                return;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i < 6; i++)
    {
        paper[i] = 5;
    }
    dfs(0);
    if (answer == 999999)
        answer = -1;
    cout << answer;
}