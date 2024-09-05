#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score[21][21];
bool check[21];
int n, answer = 987654321;
int team1[11];
int team2[11];

int calculate_team()
{
    int total = 0;
    for (int i = 0; i < n / 2 - 1; i++)
    {
        for (int j = i + 1; j < n / 2; j++)
        {
            total += score[team1[i]][team1[j]] + score[team1[j]][team1[i]];
            total -= score[team2[i]][team2[j]] + score[team2[j]][team2[i]];
        }
    }
    return total;
}

void make_team(int idx, int cur)
{
    if (cur == n / 2)
    {
        int idx1 = 0;
        int idx2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                team1[idx1] = i;
                idx++;
            }
            else
            {
                team2[idx2] = i;
                idx2++;
            }
        }
        int ctotal = abs(calculate_team());
        if (answer > ctotal)
            answer = ctotal;
    }
    else
    {
        for (int i = idx; i < n; i++)
        {
            if (!check[i])
            {
                check[i] = true;
                make_team(i + 1, cur + 1);
                check[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> score[i][j];
        }
    }
    make_team(0, 0);
    cout << answer;
}