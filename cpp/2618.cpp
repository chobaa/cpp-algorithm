#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, t;

vector<pair<int, int>> p;

int dp[1001][1001];
int police_dp[1001][1001];

int cal_distance(int police, int target, int start)
{
    int px, py, x, y;
    if (start == 1)
    {
        py = 1;
        px = 1;
    }
    else if (start == 2)
    {
        py = n;
        px = n;
    }
    else
    {
        py = p[police - 1].first;
        px = p[police - 1].second;
    }
    y = p[target - 1].first;
    x = p[target - 1].second;
    return abs(py - y) + abs(px - x);
}

int find_distance(int police1, int police2)
{
    if (police1 == t || police2 == t)
        return 0;

    int temp1, temp2, move;

    move = max(police1, police2) + 1;

    if (dp[police1][police2] != -1)
    {
        return dp[police1][police2];
    }
    if (police1 == 0)
    {
        temp1 = find_distance(move, police2) + cal_distance(police1, move, 1);
    }
    else
    {
        temp1 = find_distance(move, police2) + cal_distance(police1, move, 0);
    }
    if (police2 == 0)
    {
        temp2 = find_distance(police1, move) + cal_distance(police2, move, 2);
    }
    else
    {
        temp2 = find_distance(police1, move) + cal_distance(police2, move, 0);
    }
    dp[police1][police2] = min(temp1, temp2);
    if (temp1 < temp2)
    {
        police_dp[police1][police2] = 1;
    }
    else
    {
        police_dp[police1][police2] = 2;
    }
    return min(temp1, temp2);
}

int main()
{
    cin >> n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
            police_dp[i][j] = -1;
        }
    }
    cout << find_distance(0, 0) << "\n";

    int x = 0;
    int y = 0;
    for (int i = 0; i < t; i++)
    {
        cout << police_dp[y][x] << "\n";
        if (police_dp[y][x] == 1)
        {
            x++;
        }
        else
            y++;
    }
}