#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k, v, e;

vector<vector<int>> tree;
vector<bool> check;

void bfs(int start)
{
    check[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < tree[cur].size(); i++)
        {
            if (!check[tree[cur][i]])
            {
                check[tree[cur][i]] = true;
                q.push(tree[cur][i]);
            }
        }
    }
}

int main()
{
    cin >> k;
    while (k--)
    {
        int cnt = 0;
        cin >> v >> e;
        check.clear();
        tree.clear();
        check.resize(v + 1);
        tree.resize(v + 1);
        for (int i = 0; i < e; i++)
        {
            int from, to;
            cin >> from >> to;
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!check[i])
            {
                bfs(i);
                cnt++;
            }
        }
        if (cnt == 2)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}