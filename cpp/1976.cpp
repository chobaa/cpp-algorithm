#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[201];

int n, m;

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
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp)
                union_parent(i, j);
        }
    }
    bool check = true;
    int first;
    cin >> first;
    for (int i = 1; i < m; i++)
    {
        int temp;
        cin >> temp;
        if (find_parent(temp) != find_parent(first))
        {
            check = false;
            break;
        }
    }
    if (check)
        cout << "YES";
    else
        cout << "NO";
}