#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int ranking[501];
int indegree[501];
vector<int> graph[501];
int n,m;

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(indegree,0,sizeof(indegree));
        cin >> n;
        for(int i=1; i<=n; i++){
            int temp;
            cin >> temp;
            ranking[temp]
        }
        cin >> m;
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            indegree[a]++;
            indegree[b]--;
        }
    }
}