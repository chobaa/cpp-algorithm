#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int v,e,s;
vector<pair<int,int>> vertex[20001];
int dist[20001];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,s});
    dist[s] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost != dist[cur]) continue;
        for(auto temp : vertex[cur]){
            int next = temp.first;
            int ncost = temp.second;
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next],next});
            }
        }
    }
}

int main(){
    cin >> v >> e >> s;
    for(int i=0; i<e; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        vertex[start].push_back({end,weight});
    }
    for(int i=1; i<20001; i++){
        dist[i] = INF;
    }
    dijkstra();
    for(int i=1; i<=v; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}