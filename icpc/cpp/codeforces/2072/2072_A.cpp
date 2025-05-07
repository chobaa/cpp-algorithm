#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> p;
        k = abs(k);
        int answer = k/p;
        if(k%p != 0) answer += 1;
        if(answer > n) cout << -1 << "\n";
        else cout << answer << "\n";
    }
}