#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;
vector<int> graph[20001];
int discovered[20001];
int scc[20001];
int sccidx = 1;
int cnt = 1;
stack<int> s;

int change_val(int t, int n)
{
    return t > n ? t - n : t + n;
}

int dfs(int cur)
{
    int result = discovered[cur] = sccidx++;
    s.push(cur);

    for (auto next : graph[cur])
    {
        if (discovered[next] == 0)
            result = min(result, dfs(next));
        else if (scc[next] == 0)
            result = min(result, discovered[next]);
    }

    if (result == discovered[cur])
    {
        while (1)
        {
            int temp = s.top();
            s.pop();
            scc[temp] = cnt;
            if (temp == cur)
                break;
        }
        cnt++;
    }
    return result;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, not_a, not_b;
        cin >> a >> b;
        if (a < 0)
            a = a * -1 + n;
        if (b < 0)
            b = b * -1 + n;
        not_a = change_val(a, n);
        not_b = change_val(b, n);
        graph[not_a].push_back(b);
        graph[not_b].push_back(a);
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (discovered[i] == 0)
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (scc[i] == scc[i + n])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}