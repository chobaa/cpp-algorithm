#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int y, x;

char map[11][11];

int dp[11][1 << 10];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> y >> x;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                cin >> map[i][j];
                if(map[i][j] == 'x') dp[y][1 << x] = -1;
            }
        }
    }
}