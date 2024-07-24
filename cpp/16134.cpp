#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mul(long long x, long long y, long long p)
{
    long long ans = 1;
    while (y > 0)
    {
        if (y % 2 != 0)
        {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y /= 2;
    }
    return ans;
}

int main()
{
    long long n, r, a, b, c, p, ans;
    cin >> n >> r;
    ans = 1;
    a = 1;
    b = 1;
    p = 1000000007LL;
    for (long long i = 1; i <= n; i++)
    {
        a *= i;
        a %= p;
    }
    for (long long i = 1; i <= r; i++)
    {
        b *= i;
        b %= p;
    }
    for (long long i = 1; i <= n - r; i++)
    {
        b *= i;
        b %= p;
    }
    c = mul(b, p - 2, p);
    ans = a * c;
    ans %= p;
    cout << ans;
}