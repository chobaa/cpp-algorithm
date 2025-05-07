#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

int arr[100001];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dp[temp] = 1;
    }
    cin >> q;
    int top = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
        top = max(top,arr[i]);
    }
    for (int i = 1; i <= top; i++)
    {
        for(int j=i*2; j<=top; j += i){
            dp[j] += dp[i];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << dp[arr[i]] << "\n";
    }
}