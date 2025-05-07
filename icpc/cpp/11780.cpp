#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int weight[101][101];
int route[101][101];

vector<int> get_route(int s, int e)
{
    if (route[s][e] == s)
        return {s, e};

    vector<int> road;
    auto l = get_route(s, route[s][e]);
    auto r = get_route(route[s][e], e);
    for (auto temp : l)
        road.push_back(temp);
    road.pop_back();
    for (auto temp : r)
        road.push_back(temp);
    return road;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            weight[i][j] = 987654321;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (weight[a][b] > c)
        {
            weight[a][b] = c;
            route[a][b] = a;
        }
    }
    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (weight[i][j] > weight[i][t] + weight[t][j])
                {
                    weight[i][j] = weight[i][t] + weight[t][j];
                    route[i][j] = t;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (weight[i][j] == 987654321 || i == j)
                cout << 0 << " ";
            else
                cout << weight[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (weight[i][j] == 987654321 || i == j)
                cout << 0 << "\n";
            else
            {
                vector<int> road = get_route(i, j);
                cout << road.size() << " ";
                for (int i = 0; i < road.size(); i++)
                {
                    cout << road[i] << " ";
                }
                cout << "\n";
            }
        }
    }
}