#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, l;
    int map[101][101];
    bool row_check[101][101];
    bool col_check[101][101];
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    int answer = 0;
    // 가로 체크
    for (int i = 0; i < n; i++)
    {
        bool j_possible = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (!j_possible || abs(map[i][j] - map[i][j + 1]) >= 2)
            {
                j_possible = false;
                break;
            }
            if (map[i][j] - map[i][j + 1] == -1)
            {
                for (int slide = j; slide >= j + 1 - l; slide--)
                {
                    if (row_check[i][slide] || slide < 0 || map[i][j] != map[i][slide])
                    {
                        j_possible = false;
                        break;
                    }
                    if (slide == j + 1 - l)
                    {
                        for (int slide = j; slide >= j + 1 - l; slide--)
                            row_check[i][slide] = true;
                    }
                }
            }
            else if (map[i][j] - map[i][j + 1] == 1)
            {
                for (int slide = j + 1; slide <= j + l; slide++)
                {
                    if (row_check[i][slide] || slide >= n || map[i][j + 1] != map[i][slide])
                    {
                        j_possible = false;
                        break;
                    }
                    if (slide == j + l)
                    {
                        for (int slide = j + 1; slide <= j + l; slide++)
                            row_check[i][slide] = true;
                    }
                }
            }
        }
        if (j_possible)
            answer++;
    }
    // 세로 체크
    for (int i = 0; i < n; i++)
    {
        bool i_possible = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (!i_possible || abs(map[j][i] - map[j + 1][i]) >= 2)
            {
                i_possible = false;
                break;
            }
            if (map[j][i] - map[j + 1][i] == -1)
            {
                for (int slide = j; slide >= j + 1 - l; slide--)
                {
                    if (col_check[slide][i] || slide < 0 || map[j][i] != map[slide][i])
                    {
                        i_possible = false;
                        break;
                    }
                    if (slide == j + 1 - l)
                        for (int slide = j; slide >= j + 1 - l; slide--)
                            col_check[slide][i] = true;
                }
            }
            else if (map[j][i] - map[j + 1][i] == 1)
            {
                for (int slide = j + 1; slide <= j + l; slide++)
                {
                    if (col_check[slide][i] || slide >= n || map[j + 1][i] != map[slide][i])
                    {
                        i_possible = false;
                        break;
                    }
                    if (slide == j + l)
                        for (int slide = j + 1; slide <= j + l; slide++)
                            col_check[slide][i] = true;
                }
            }
        }
        if (i_possible)
            answer++;
    }

    cout << answer;
}