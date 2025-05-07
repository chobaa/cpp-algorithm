#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        int k;
        cin >> k;
        vector<int> v(k+1);
        for(int i=0; i<k; i++){
            cin >> v[i];
        }
        int temp = v[0];
        for(int i=1; i<k; i++){
            temp = gcd(temp,v[i]);
        }
        if(x % temp == 0 && y % temp == 0){
            cout << "Ta-da\n";
        }
        else cout << "Gave up\n";
    }
}