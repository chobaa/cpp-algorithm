#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1e9 + 7;

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans1 = 0, cnt = 1;
    for (long long i = 1; i <= n; i++)
    {
        ans1 = (ans1 + ((i * i) % MOD * (i + 1)) % MOD) % MOD;
    }
    for (long long i = 2; i <= n; i++)
    {
        cnt = (((cnt * i) % MOD) * i) % MOD;
    }
    cout << ans1 << " " << cnt << "\n";
}