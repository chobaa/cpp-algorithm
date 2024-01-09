#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int list[4000001];

int main()
{
    int n, answer = 0;
    cin >> n;
    vector<int> prime;
    for (int i = 2; i <= n; i++)
    {
        list[i] = i;
    }
    // 소수 구하기
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (list[i] == 0)
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            list[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (list[i] != 0)
            prime.push_back(i);
    }
    for (int i = 0; i < prime.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < prime.size(); j++)
        {
            sum += prime[j];
            if (sum == n)
                answer++;
            else if (sum > n)
                break;
        }
    }

    cout << answer;
}