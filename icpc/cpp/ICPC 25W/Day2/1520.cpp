#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cnt[501][501];
int height[501][501];

int n, m;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()){
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({1,{0,0}});
        
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
        }
    }
    bfs();
    cout << cnt[m - 1][n - 1];
}