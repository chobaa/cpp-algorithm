#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    pair<int, int> p1, p2, p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    int a = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
    if (a > 0)
        cout << 1;
    if (a == 0)
        cout << 0;
    if (a < 0)
        cout << -1;
}