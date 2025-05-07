#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;

long long isprime(long long a)
{
    if (a == 2)
        return 0;
    if (a % 2 == 0 && a != 2)
        return 2;
    for (int i = 3; i < a; i++)
    {
        if (sqrtl(a) < i)
            return 0;
        if (a % i == 0)
            return i;
    }
    return 0;
}

int main()
{
    cin >> n;
    long long p = isprime(n);
    if (p != 0)
    {
        n /= p;
        p = isprime(n);
        if (p == 0)
        {
            cout << "cubelover\n";
            return 0;
        }
    }
    cout << "koosaga\n";
}