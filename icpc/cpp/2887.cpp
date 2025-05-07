#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> check;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    check.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(make_tuple(x, y, z));
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            double x = get<0>(v[i]);
            double y = get<1>(v[i]);
            double z = get<2>(v[i]);
            for (int j = i + 1; j < n; j++)
            {
                long double minimum = 1000000001;
                if (!check[j])
                {
                    double x2 = get<0>(v[j]);
                    double y2 = get<1>(v[j]);
                    double z2 = get<2>(v[j]);
                }
            }
        }
    }
}