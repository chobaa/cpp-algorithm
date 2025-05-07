#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, l;
vector<pair<long long, long long>> ant;
long long left_ant = 0, right_ant = 0, leftcount = 0, rightcount = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        long long temp;
        cin >> temp;
        if (temp > 0)
        {
            right_ant = max(right_ant, l - temp);
            rightcount++;
        }
        else
        {
            temp *= -1;
            left_ant = max(left_ant, temp);
            leftcount++;
        }
        ant.push_back({temp, i});
    }
    sort(ant.begin(), ant.end());
    if (left_ant < right_ant)
    {
        cout << ant[leftcount].second << " " << right_ant;
    }
    else
    {
        cout << ant[leftcount - 1].second << " " << left_ant;
    }
}