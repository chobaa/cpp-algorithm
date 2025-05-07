#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,l;
        cin >> l >> n;
        int lowest = 0,highest = 0;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            // 최소 시간 구하기
            if(temp > l / 2){
                lowest = max(lowest,l-temp);
            }
            else lowest = max(temp,lowest);
            // 최대 시간 구하기
            highest = max(highest,l -temp);
            highest = max(highest,temp);
        }
        cout << lowest << " " << highest << "\n";
    }
}