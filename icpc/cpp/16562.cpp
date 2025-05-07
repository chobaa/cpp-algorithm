#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int cost[10002];
int parent[10002];

int find_parent(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);
    if (cost[a] < cost[b])
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    int answer = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_parent(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            answer += cost[i];
            if (answer > k)
            {
                cout << "Oh no";
                return 0;
            }
        }
    }
    cout << answer;
}