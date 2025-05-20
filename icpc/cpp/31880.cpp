#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        answer += temp;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 0) continue;
        answer *= temp;
    }
    cout << answer;
}