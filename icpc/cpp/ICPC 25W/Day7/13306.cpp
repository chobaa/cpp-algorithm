#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[200001];
vector<tuple<int, int, int>> command;
vector<string> answer;

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

int n, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    parent[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        parent[i] = a;
    }
    for (int i = 0; i < n - 1 + q; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 0)
        {
            command.push_back(make_tuple(a, b, parent[b]));
            parent[b] = b;
        }
        else
        {
            cin >> c;
            command.push_back(make_tuple(a, b, c));
        }
    }
    for (int i = 2; i <= n; i++)
    {
        union_parent(parent[i], i);
    }
    for (int i = n + q - 2; i >= 0; i--)
    {
        if (get<0>(command[i]) == 0)
        {
            union_parent(get<1>(command[i]), get<2>(command[i]));
        }
        else
        {
            int a = find_parent(get<1>(command[i]));
            int b = find_parent(get<2>(command[i]));
            if (a == b)
                answer.push_back("YES");
            else
                answer.push_back("NO");
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        cout << answer[i] << "\n";
    }
}