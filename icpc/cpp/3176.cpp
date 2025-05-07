#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int parent[100001][17];
int min_road[100001][17];
int max_road[100001][17];
int depth[100001];
vector<pair<int, int>> graph[100001];

int n, m;

pair<int, int> calculate(int a, int b)
{
    int min_result = 1000001, max_result = 0;

    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];
    int idx = 0;
    while (diff)
    {
        // diff를 2의 제곱수로 분해한다고 생각하면 편함.
        // if(diff) == 7, 7 -> 111이고, 4,2,1칸 점프가 필요함.
        if (diff % 2)
        {
            min_result = min(min_result, min_road[a][idx]);
            max_result = max(max_result, max_road[a][idx]);
            a = parent[a][idx];
        }
        diff /= 2;
        idx++;
    }

    if (a != b)
    {
        for (int i = 16; i >= 0; i--)
        {
            if (parent[a][i] != 0 && parent[a][i] != parent[b][i])
            {
                min_result = min(min_result, min(min_road[a][i], min_road[b][i]));
                max_result = max(max_result, max(max_road[a][i], max_road[b][i]));
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        min_result = min(min_result, min(min_road[a][0], min_road[b][0]));
        max_result = max(max_result, max(max_road[a][0], max_road[b][0]));
    }
    return {min_result, max_result};
}

void find_parent(int cur)
{
    for (pair<int, int> next : graph[cur])
    {
        if (depth[next.first] == -1)
        {
            parent[next.first][0] = cur;
            depth[next.first] = depth[cur] + 1;
            min_road[next.first][0] = max_road[next.first][0] = next.second;
            find_parent(next.first);
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
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    memset(parent, 0, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    memset(min_road, 1000001, sizeof(min_road));
    memset(max_road, 0, sizeof(max_road));

    depth[1] = 0;
    find_parent(1);

    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parent[j][i - 1] != 0)
            {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
                min_road[j][i] = min(min_road[parent[j][i - 1]][i - 1], min_road[j][i - 1]);
                max_road[j][i] = max(max_road[parent[j][i - 1]][i - 1], max_road[j][i - 1]);
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = calculate(a, b);
        cout << result.first << " " << result.second << "\n";
    }
}