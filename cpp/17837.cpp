#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
string map[13][13];
int board[13][13];
int dir[13];
pair<int, int> loc[13];
int answer = 0;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = to_string(i);
        dir[i] = c;
    }
    while (1)
    {
        answer++;
        for (int i = 0; i < k; i++)
        {
        }
    }
}