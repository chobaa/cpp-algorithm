#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, q;

vector<int> graph[100001];
bool visited[100001];
int cnt[100001];

void make_tree(int cur)
{
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!visited[next])
        {
            make_tree(next);
            cnt[cur] += cnt[next];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        cnt[i] = 1;
    make_tree(r);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        cout << cnt[a] << "\n";
    }
}