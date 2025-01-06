#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int n, m;
vector<int> graph[100001];
stack<int> s;
int discovered[100001];
int SCCid[100001];
int indegree[100001];
int idx, SCCcnt;

int dfs(int cur)
{
    int result = discovered[cur] = idx++;
    s.push(cur);

    for (auto next : graph[cur])
    {
        if (discovered[next] == 0)
        {
            result = min(result, dfs(next));
        }
        else if (SCCid[next] == 0)
            result = min(result, discovered[next]);
    }

    if (result == discovered[cur])
    {
        while (1)
        {
            int temp = s.top();
            s.pop();
            SCCid[temp] = SCCcnt;
            if (temp == cur)
                break;
        }
        SCCcnt++;
    }
    return result;
}

void init()
{
    for (int i = 0; i <= n; i++)
        graph[i].clear();
    memset(discovered, 0, sizeof(discovered));
    memset(indegree, 0, sizeof(indegree));
    memset(SCCid, 0, sizeof(SCCid));
    idx = SCCcnt = 1;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void solve()
{
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (discovered[i] == 0)
            dfs(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto w : graph[i])
        {
            if (SCCid[w] == SCCid[i])
                continue;
            indegree[SCCid[w]]++;
        }
    }

    for (int i = 1; i < SCCcnt; i++)
    {
        if (indegree[i] == 0)
            answer++;
    }
    cout << answer << "\n";
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;

        init();
        solve();
    }

    return 0;
}