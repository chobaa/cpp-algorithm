#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int parent[500001];

int Find(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (a >= b)
        {
            parent[a] = b;
        }
        else
            parent[b] = a;
    }
}

bool Parent(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (Parent(a, b))
        {
            cout << i + 1;
            return 0;
        }
        Union(a, b);
    }
    cout << "0";
}