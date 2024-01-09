#include <iostream>

using namespace std;

long long cnt[10];

void calc(long long a, long long digit)
{
    while (a > 0)
    {
        cnt[a % 10] += digit;

        a /= 10;
    }
}

void solve(long long a, long long b, long long digit)
{
    while (a % 10 != 0 && a <= b)
    {
        calc(a, digit);
        a++;
    }
    if (a > b)
        return;

    while (b % 10 != 9 && b >= a)
    {
        calc(b, digit);
        b--;
    }

    long long count = (b / 10 - a / 10 + 1);

    for (int i = 0; i < 10; ++i)
    {
        cnt[i] += count * digit;
    }

    solve(a / 10, b / 10, digit * 10);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    solve(1, n, 1);

    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i] << " ";
    }
}