#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prime[5000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2; i<5000001; i++){
        if(!prime[i]){
            for(int j=i*2; j<5000001; j += i){
                if(prime[j] == 0) prime[j] = i;
            }
            prime[i] = 1;
        }
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        while(1){
            if(prime[temp] == 1){
                cout << temp << " ";
                break;
            }
            else cout << prime[temp] << " ";
            temp /= prime[temp];
        }
        cout << "\n";
    }
}