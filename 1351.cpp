#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> cache;

long long p, q;

long long solve(long long n)
{
    if (n == 0)
        return 1;
    if (cache[n] != 0)
        return cache[n];

    return cache[n] = solve(n / p) + solve(n / q);
}

int main()
{
    long long n;
    cin >> n >> p >> q;
    cout << solve(n);
}