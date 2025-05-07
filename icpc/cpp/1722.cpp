#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, mode, k;
vector<int> p;
vector<int> arr;
vector<int> list;

int main()
{
    int f[21];
    bool check[21];
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 21; i++)
    {
        f[i] = f[i - 1] * i;
    }

    cin >> n >> mode;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i + 1);
    }
    if (mode == 1)
    {
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                    continue;
                if (f[n - i - 1] < k)
                {
                    k -= f[n - i - 1];
                }
                else
                {
                    list.push_back(j);
                    check[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << list[i] << " ";
        }
    }
    else
    {
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            p.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < p[i]; j++)
            {
                if (!check[j])
                    answer += f[n - i - 1];
            }
            check[p[i]] = true;
        }
        cout << answer + 1;
    }
}