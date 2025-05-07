#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> position[12];

int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int pos, val;
        cin >> pos >> val;
        position[pos].push(val);
    }
    long long sum = 0;
    for (int i = 1; i <= 11; i++)
    {
        if (position[i].size() == 0)
            continue;
        int last = k;
        while(last > 0){
            int cur = position[i].top();
            position[i].pop();
            if(cur == 0) break;
            cur--;
            last--;
            position[i].push(cur);
        }
        sum += position[i].top();
    }
    cout << sum;
}