#include <iostream>

using namespace std;

int dp[1001];

int main(){
    dp[0] = 3;
    int n, idx = 0;
    cin >> n;
    while(n > dp[idx]){
        idx++;
        dp[idx] = dp[idx-1] * 2 + (idx+3);
    }
    while(1){
        if(idx == 0){
            if(n == 1) cout << "m";
            else cout << "o";
            break;
        }
        else if(n < dp[idx-1]){
            idx--;
        }
        else if(n < dp[idx-1] + idx + 3){
            if(n == dp[idx-1] + 1){
                cout << "m";
            }
            else cout << "o";
            break;
        }
        else{
            n -= (dp[idx-1] + idx + 3);
            idx--;
        }
    }
}