#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, dice_y, dice_x, k;

int map[21][21];

int dice[6];

void roll(int oper)
{
    int temp = dice[0];
    if (oper == 1)
    {
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    if (oper == 2)
    {
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    if (oper == 4)
    {
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
    if (oper == 3)
    {
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
}

int main()
{
    cin >> n >> m >> dice_x >> dice_y >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int oper;
        cin >> oper;
        if (oper == 1)
        {
            if (dice_x + 1 < m)
            {
                roll(1);
                dice_x++;
                if (map[dice_y][dice_x] == 0)
                {
                    map[dice_y][dice_x] = dice[0];
                }
                else
                {
                    dice[0] = map[dice_y][dice_x];
                    map[dice_y][dice_x] = 0;
                }
                cout << dice[5] << "\n";
            }
        }
        if (oper == 2)
        {
            if (dice_x - 1 >= 0)
            {
                roll(2);
                dice_x--;
                if (map[dice_y][dice_x] == 0)
                {
                    map[dice_y][dice_x] = dice[0];
                }
                else
                {
                    dice[0] = map[dice_y][dice_x];
                    map[dice_y][dice_x] = 0;
                }
                cout << dice[5] << "\n";
            }
        }
        if (oper == 4)
        {
            if (dice_y + 1 < n)
            {
                roll(4);
                dice_y++;
                if (map[dice_y][dice_x] == 0)
                {
                    map[dice_y][dice_x] = dice[0];
                }
                else
                {
                    dice[0] = map[dice_y][dice_x];
                    map[dice_y][dice_x] = 0;
                }
                cout << dice[5] << "\n";
            }
        }
        if (oper == 3)
        {
            if (dice_y - 1 >= 0)
            {
                roll(3);
                dice_y--;
                if (map[dice_y][dice_x] == 0)
                {
                    map[dice_y][dice_x] = dice[0];
                }
                else
                {
                    dice[0] = map[dice_y][dice_x];
                    map[dice_y][dice_x] = 0;
                }
                cout << dice[5] << "\n";
            }
        }
    }
}