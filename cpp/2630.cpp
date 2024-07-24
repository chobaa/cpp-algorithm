#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[129][129];
int blue, white;

void divide_and_conquer(int y_start, int x_start, int size)
{
    int basic_color = 0;
    if (map[y_start][x_start] == 1)
        basic_color = 1;
    for (int y = y_start; y < y_start + size; y++)
    {
        for (int x = x_start; x < x_start + size; x++)
        {
            if (map[y][x] != basic_color)
            {
                if (size == 1)
                    if (basic_color == 0)
                    {
                        white++;
                    }
                    else
                    {
                        blue++;
                    }
                else
                {
                    divide_and_conquer(y_start, x_start, size / 2);
                    divide_and_conquer(y_start + size / 2, x_start, size / 2);
                    divide_and_conquer(y_start, x_start + size / 2, size / 2);
                    divide_and_conquer(y_start + size / 2, x_start + size / 2, size / 2);
                }
                return;
            }
        }
    }
    if (basic_color == 0)
    {
        white++;
    }
    else
    {
        blue++;
    }
    return;
}

int main()
{
    blue = 0, white = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    divide_and_conquer(0, 0, n);

    cout << white << "\n"
         << blue;
}