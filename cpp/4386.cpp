#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

pair<double, double> star[101];
vector<pair<double, pair<int, int>>> cost;
int parent[101];

int get_parent(int x)
{
    if (x != parent[x])
        return parent[x] = get_parent(parent[x]);
    else
        return x;
}

void union_parent(int x, int y)
{
    x = get_parent(x);
    y = get_parent(y);
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
    return;
}

int main()
{
    int n;
    cin >> n;
    double answer;
    for (int i = 0; i < n; i++)
    {
        cin >> star[i].first >> star[i].second;
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cost.push_back({(sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2))), {i, j}});
        }
    }
    sort(cost.begin(), cost.end());
    for (int i = 0; i < cost.size(); i++)
    {
        double value = cost[i].first;
        int s1 = cost[i].second.first;
        int s2 = cost[i].second.second;
        if (get_parent(s1) != get_parent(s2))
        {
            union_parent(s1, s2);
            answer += value;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;
}