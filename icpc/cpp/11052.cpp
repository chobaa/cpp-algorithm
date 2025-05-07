#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int price[1001];
long long avp[1001];
int answer = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    avp[0] = 0;
    avp[1] = price[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            avp[i] = max(price[j] + avp[i - j], avp[i]);
        }
    }
    cout << avp[n];
}