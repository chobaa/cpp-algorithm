#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int energy[100001];
vector<pair<int, int>> v[100001];

int parent[20][100001];
int sparse[20][100001];

void make_tree(int cur, int before)
{
    parent[0][cur] = before;
    for (auto next : v[cur])
    {
        if (next.first != before)
        {
            sparse[0][next.first] = next.second;
            make_tree(next.first, cur);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> energy[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    make_tree(1, 0);
    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            sparse[k][i] = sparse[k - 1][i] + sparse[k - 1][parent[k - 1][i]];
            parent[k][i] = parent[k - 1][parent[k - 1][i]];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int pos = i + 1, energys = energy[i];
        for (int j = 19; j >= 0; j--)
        {
            if (parent[j][pos] != 0 && energys >= sparse[j][pos])
            {
                energys -= sparse[j][pos];
                pos = parent[j][pos];
            }
        }
        cout << pos << "\n";
    }
}