#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer = 1;

vector<int> graph[1000001];
bool visited[1000001];
int dp[1000001][2];

void make_tree(int cur)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!visited[next])
        {
            make_tree(next);
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    make_tree(1);
    cout << min(dp[1][0], dp[1][1]);
}