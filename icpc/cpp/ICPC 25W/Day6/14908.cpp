#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
vector<tuple<double, double, int>> shoes;

bool cmp(const tuple<double, double, int> a, const tuple<double, double, int> b)
{
    double cost1, cost2;
    cost1 = get<1>(a) / get<0>(a);
    cost2 = get<1>(b) / get<0>(b);
    if (cost1 == cost2)
        return get<2>(a) < get<2>(b);
    return cost1 > cost2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double b, c;
        cin >> b >> c;
        shoes.push_back(make_tuple(b, c, i + 1));
    }
    sort(shoes.begin(), shoes.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << get<2>(shoes[i]) << " ";
    }
}