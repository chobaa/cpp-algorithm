#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10

using namespace std;

int bulb[11][11];
int change[11][11];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int ans = 987654321;

void init(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            change[i][j] = bulb[i][j];
        }
    }
}

void lightup(int y, int x){
    if(change[y][x]) change[y][x] = 0;
    else change[y][x] = 1;
    for(int i=0; i<4; i++){
        int cy = y + dy[i];
        int cx = x + dx[i];
        if(cy < 0 || cy >= MAX || cx < 0 || cx >=MAX) continue;
        if(change[cy][cx]) change[cy][cx] = 0;
        else change[cy][cx] = 1;
    }
}

bool isclear(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(change[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // stdio
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char temp;
            cin >> temp;
            if(temp == '#') bulb[i][j] = 0;
            else bulb[i][j] = 1;
        }
    }

    for(int temp = 0; temp < (1 << MAX); temp++){

        int cnt = 0;
        // 매번 새로 초기화
        init();
        // 첫줄 비트마스킹
        for(int bit = 0; bit < MAX; bit++){
            if(temp & (1 << bit)){
                lightup(0, bit);
                cnt++;
            }
        }
        for(int i=0; i<MAX-1; i++){
            for(int j=0; j<MAX; j++){
                if(change[i][j]){
                    lightup(i+1,j);
                    cnt++;
                }
            }
        }

        if(isclear()) ans = min(ans,cnt);
    }
    if(ans == 987654321) cout << -1;
    else cout << ans;
}