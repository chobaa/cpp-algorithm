#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[500001];

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
    int n, p;
    cin >> n >> p;
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < p; i++)
    {
        int a;
        cin >> a;
        while(a > 0){
            if (a == parent[a])
            {
                union_parent(a, a - 1);
                break;
            }
            a = find_parent(a);
        }
        if (a == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << p;
}