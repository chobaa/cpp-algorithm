#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long double CCW(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c)
{
    return (long double)(a.first * b.second) + (b.first * c.second) + (a.second * c.first) -
           (b.first * a.second) - (c.first * b.second) - (a.first * c.second);
}

int main()
{
    long long answer = 0;
    int n;
    cin >> n;
    vector<pair<long double, long double>> v;
    for (int i = 0; i < n; i++)
    {
        long double temp, temp2;
        cin >> temp >> temp2;
        v.push_back({temp, temp2});
    }
    for (int i = 1; i < n - 1; i++)
    {
        answer += CCW(v[0], v[i], v[i + 1]) / (double)2;
    }
    cout << fixed;
    cout.precision(1);

    cout << fabs(answer);
}