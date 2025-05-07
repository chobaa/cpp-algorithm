#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 17 // 2^16 > 50000

using namespace std;

int n,m;

vector<int> graph[50001];
int depth[50001];
int parent[MAX][50001];

void make_tree(int cur){
    for(auto next : graph[cur]){
        if(depth[next] == -1){
            depth[next] = depth[cur] + 1;
            parent[0][next] = cur;
            make_tree(next);
        }
    }
}

int lca(int a, int b){
    if(depth[b] < depth[a]) swap(a,b);
    for(int i=MAX-1; i>=0; i--){
        if(depth[b] - (1 << i) >= depth[a]){
            b = parent[i][b];
        }
    }
    if(b == a) return a;
    else{
        for(int i=MAX-1; i>=0; i--){
            if(parent[i][a] != parent[i][b]){
                a = parent[i][a];
                b = parent[i][b];
            }
        }
    }
    return parent[0][a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        depth[i] = -1;
        parent[0][i] = i;
    }
    depth[1] = 0;
    make_tree(1);

    // binary
    for(int i=1; i<MAX; i++){
        for(int j=1; j<=n; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }
}