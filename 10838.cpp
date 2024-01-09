#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int parent[100001];
int parent2[100001];
int color[100001];
int n, k;

int find_common(int a, int b, int c)
{
    if (a == b)
        return a;
    while (1)
    {
        parent2[a] = c;
        if (a == 0)
            break;
        a = parent[a];
    }
    while (1)
    {
        if (parent2[b] == c)
            return b;
        b = parent[b];
    }
}

void draw_color(int a, int b, int c, int d)
{
    while (a != d)
    {
        color[a] = c;
        a = parent[a];
    }
    while (b != d)
    {
        color[b] = c;
        b = parent[b];
    }
}

int count_color(int a, int b, int c)
{
    set<int> colors;
    while (a != c)
    {
        colors.insert(color[a]);
        a = parent[a];
    }
    while (b != c)
    {
        colors.insert(color[b]);
        b = parent[b];
    }
    return colors.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    parent[0] = -1;
    for (int i = 1; i <= k; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int d = find_common(a, b, i);
            draw_color(a, b, c, d);
        }
        if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            parent[a] = b;
        }
        if (op == 3)
        {
            int a, b;
            cin >> a >> b;
            int c = find_common(a, b, i);
            cout << count_color(a, b, c) << "\n";
        }
    }
}