#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int v, e;
bool visited[10001];
vector<int> graph[10001];
stack<int> s;
int parent[10001];
int idx = 1;
vector<vector<int>> answer;

int dfs(int cur)
{
    parent[cur] = idx++;
    s.push(cur);

    int result = parent[cur];
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (parent[next] == 0)
            result = min(result, dfs(next));
        else if (!visited[next])
            result = min(result, parent[next]);
    }
    if (result == parent[cur])
    {
        vector<int> temp;
        while (1)
        {
            int t = s.top();
            s.pop();
            temp.push_back(t);
            visited[t] = true;
            if (t == cur)
                break;
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp);
    }
    return result;
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for (auto a : answer)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << "-1\n";
    }
}