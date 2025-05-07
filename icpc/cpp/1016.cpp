#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
    long long start, end;
    cin >> start >> end;
    for (long long i = 2; i * i <= end; i++)
    {
        long long quotient = start / (i * i);
        if (start % (i * i))
            quotient++;
        while (quotient * i * i <= end)
        {
            dp[quotient * i * i - start] = 1;
            quotient++;
        }
    }
    int answer = 0;
    for (int i = 0; i <= end - start; i++)
    {
        if (!dp[i])
            answer++;
    }
    cout << answer;
}