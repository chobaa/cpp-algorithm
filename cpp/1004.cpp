#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int answer = 0;
        int x1, y1, x2, y2;
        int n;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            long double dist_a = pow((x - x1), 2) + pow((y - y1), 2) - pow(r, 2);
            long double dist_b = pow((x - x2), 2) + pow((y - y2), 2) - pow(r, 2);
            if (dist_a * dist_b < 0)
                answer++;
        }
        cout << answer << "\n";
    }
}