#include <iostream>
#define MOD 1000000000

using namespace std;

long long arr[1027][11][102];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
        arr[1 << i][i][1] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 1; k < 1024; k++)
            {
                int idx = 1 << j;
                if (arr[k][j][i] != 0)
                {
                    if (j == 0)
                        arr[k | 1 << 1][j + 1][i + 1] = (arr[k | 1 << 1][j + 1][i + 1] + arr[k][j][i]) % MOD;
                    else if (j == 9)
                        arr[k | 1 << 8][j - 1][i + 1] = (arr[k | 1 << 8][j - 1][i + 1] + arr[k][j][i]) % MOD;
                    else
                    {
                        arr[k | 1 << (j + 1)][j + 1][i + 1] = (arr[k | 1 << (j + 1)][j + 1][i + 1] + arr[k][j][i]) % MOD;
                        arr[k | 1 << (j - 1)][j - 1][i + 1] = (arr[k | 1 << (j - 1)][j - 1][i + 1] + arr[k][j][i]) % MOD;
                    }
                }
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        int idx = (1 << 10) - 1;
        sum += arr[idx][i][n];
    }
    cout << sum % MOD << "\n";
}