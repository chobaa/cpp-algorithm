#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n < i)
            break;
        n -= i;
        count++;
    }
    cout << count;
}