#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007
using namespace std;

long long getpow(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        long long plus = getpow(2, i);
        long long minus = getpow(2, n - i - 1);
        answer = (answer + (((plus - minus) % MOD) * (arr[i] % MOD)) % MOD + MOD) % MOD;
    }
    cout << answer;
}