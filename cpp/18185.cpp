#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int num[10003];
    long long answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    num[n] = 0;
    num[n + 1] = 0;
    for (int i = 0; i < n; i++)
    {
        int three_buy;
        int two_buy;
        if (num[i + 1] <= num[i + 2])
        {
            three_buy = min(num[i], min(num[i + 1], num[i + 2]));
            answer += three_buy * 7;
            num[i] -= three_buy;
            num[i + 1] -= three_buy;
            num[i + 2] -= three_buy;
            two_buy = min(num[i], num[i + 1]);
            answer += two_buy * 5;
            num[i] -= two_buy;
            num[i + 1] -= two_buy;
        }
        else
        {
            two_buy = min(num[i], num[i + 1] - num[i + 2]);
            answer += two_buy * 5;
            num[i] -= two_buy;
            num[i + 1] -= two_buy;
            three_buy = min(num[i], min(num[i + 1], num[i + 2]));
            answer += three_buy * 7;
            num[i] -= three_buy;
            num[i + 1] -= three_buy;
            num[i + 2] -= three_buy;
        }
        // 나머지 구매
        answer += num[i] * 3;
        num[i] = 0;
    }
    cout << answer;
}