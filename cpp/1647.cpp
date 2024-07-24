#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int parent[100001];

int answer = 0;

int get_parent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = get_parent(parent[x]);
}

bool find_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a == b)
        return true;
    return false;
}

void union_parent(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

struct compare
{
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> cost;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        cost.push({weight, {start, end}});
    }
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    while (count < n - 2)
    {
        int a = cost.top().second.first;
        int b = cost.top().second.second;
        if (!find_parent(a, b))
        {
            answer += cost.top().first;
            union_parent(a, b);
            count++;
        }
        cost.pop();
    }
    cout << answer;
}
