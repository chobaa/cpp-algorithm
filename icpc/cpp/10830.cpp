#include <iostream>
#include <vector>

using namespace std;

int n;
long long k;

long long temp[5][5];
long long matrix[5][5];
long long ans[5][5];

void matrix_multiply(long long a[5][5], long long b[5][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (int t = 0; t < n; t++)
            {
                temp[i][j] += (a[i][t] * b[t][j]);
            }
            temp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[i][j];
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        ans[i][i] = 1;
    }
    while (k > 0)
    {
        if (k % 2 == 1)
            matrix_multiply(ans, matrix);
        matrix_multiply(matrix, matrix);
        k /= 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}