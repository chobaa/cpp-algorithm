#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

struct Coor
{
    long long x, y;
};
vector<Coor> point;
stack<Coor> s;

long long CCW(Coor a, Coor b, Coor c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
}

bool minCCW(Coor a, Coor b)
{
    long long Value = CCW(point[0], a, b);
    if (Value)
        return Value > 0;
    else if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        point.push_back({a, b});
    }
    for (int i = 1; i < n; i++)
    {
        if (point[0].y == point[i].y)
        {
            if (point[0].x > point[i].x)
                swap(point[0], point[i]);
        }
        else if (point[0].y > point[i].y)
            swap(point[0], point[i]);
    }
    sort(point.begin() + 1, point.end(), minCCW);
    s.push(point[0]);
    s.push(point[1]);
    for (int i = 2; i < n; i++)
    {
        while (s.size() >= 2)
        {
            Coor temp2 = s.top();
            s.pop();
            Coor temp = s.top();
            if (CCW(temp, temp2, point[i]) > 0)
            {
                s.push(temp2);
                break;
            }
        }
        s.push(point[i]);
    }
    cout << s.size() << "\n";
}