#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
const int INF = 123456789;
 
void set_graph(std::vector<std::vector<int>>& graph, const int u, const int v, const int c)
{
    graph[u][v] = c;
    //graph[v][u] = -c;
}
 
int dfs(const int cur, const int capacity, const int sink, const int n, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    if (visited[cur])
        return 0;
    visited[cur] = true;
    if (cur == sink)
        return capacity;
 
    for (int v = 0; v < n; v++) {
        if (graph[cur][v] > 0) {
            int cur_capacity = graph[cur][v];
            if (capacity != 0 && cur_capacity > capacity) {
                cur_capacity = capacity;
            }
            int f = dfs(v, cur_capacity, sink, n, graph, visited);
            if (f) {
                graph[cur][v] -= f;
                graph[v][cur] += f;
                return f;
            }
        }
    }
 
    return 0;
}
 
int ford_fulkerson(const int source, const int sink, const int n, std::vector<std::vector<int>>& graph)
{
    std::vector<bool> visited(n, false);
 
    int max_flow{}, cur_flow{};
    while (1) {
        fill(visited.begin(), visited.end(), false);
        cur_flow = dfs(source, 0, sink, n, graph, visited);
        if (cur_flow == 0)
            break;
        max_flow += cur_flow;
    }
 
    return max_flow;
}
 
int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> graph;
    // set graph
    int n{}, m{};
    scanf("%d %d", &n, &m);
    int total{}, e{};
    total = n + m;
    graph.resize(total +2, std::vector<int>(total +2, 0));
 
    // add edges outgoing from source(0)
    for (int i = 1; i <= n; i++) {
        set_graph(graph, 0, i, 1);
    }
    // add edges incoming to sink(n+m+1 = total+1)
    for (int i = n + 1; i <= total; i++) {
        set_graph(graph, i, total + 1, 1);
    }
 
    int s, v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &s);
        for (int j = 0; j < s; j++) {
            scanf("%d", &v);
            set_graph(graph, i + 1, n + v, 1);
        }
    }
    
    // source: 0, sink: n+1
    // start
    auto result = ford_fulkerson(0, total +1, total +2, graph);
    std::cout << result << "\n";
}