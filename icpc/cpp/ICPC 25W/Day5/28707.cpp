#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n,m;
vector<int> arr;
vector<pair<int,pair<int,int>>> control;
map<vector<int>,int> dist;

void dijkstra(){
    priority_queue<pair<int,vector<int>>> pq;
    pq.push({0,arr});
    while(!pq.empty()){
        int cur = -pq.top().first;
        vector<int> before = pq.top().second;
        pq.pop();
        if(dist[before] != cur) continue;
        for(int i=0; i<m; i++){
            vector<int> temp = before;
            swap(temp[control[i].first],temp[control[i].second.first]);
            if(dist.find(temp) == dist.end() || dist[temp] > dist[before] + control[i].second.second){
                dist[temp] = dist[before] + control[i].second.second;
                pq.push({-dist[temp],temp});
            }
        }
    }
}

int main(){
    cin >> n;
    arr.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        control.push_back({a-1,{b-1,c}});
    }
    dijkstra();
    sort(arr.begin(),arr.end());
    if(dist.find(arr) == dist.end()) cout << -1;
    else cout << dist[arr];
}