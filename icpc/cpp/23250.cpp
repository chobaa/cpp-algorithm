#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    n = pow(2, n-1);
    long long n2 = n / 2;
    int from = 1, via = 2, to = 3;
    while (1)
    {
        if (k == n)
        {
            cout << from << " " << to << "\n";
            break;
        }
        else if (k < n)
        {
            swap(via, to);
            n -= n2;
        }
        else if (k > n)
        {
            swap(from, via);
            n += n2;
        }
        n2 /= 2;
    }
}