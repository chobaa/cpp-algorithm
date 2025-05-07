#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ba[31];
int bb[31];

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        for(int i = 30; i>=0; i--){
            ba[i] = (a >> i) & 1;
            bb[i] = (b >> i) & 1;
        }
        
    }
}