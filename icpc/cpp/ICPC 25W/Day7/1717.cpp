#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000001];

int find_parent(int a)
{
    if (parent[a] == a)
        return parent[a];
    else
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            union_parent(b, c);
        }
        else
        {
            b = find_parent(b);
            c = find_parent(c);
            if (b == c)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}