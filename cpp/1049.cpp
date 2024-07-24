#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, six = 9999, one = 9999, answer = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        one = min(one, b);
        six = min(six, a);
    }
    if (one * 6 < six)
        six = one * 6;
    if (one * (n % 6) > six)
    {
        n -= n % 6;
        answer += six;
    }
    while (n > 0)
    {
        if (n >= 6)
        {
            answer += six;
            n -= 6;
        }
        else
        {
            answer += one;
            n--;
        }
    }
    cout << answer;
}