#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, answer = 0;
int arr[1001];
int dp[1001];
int before[1001];
vector<int> result;
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    before[i] = j;
                }
            }
        }
        answer = max(answer, dp[i]);
    }
    int max_node = 0;
    for(int i=0; i<n; i++){
        if(dp[i] == answer){
            max_node = i;
            break;
        }
    }
    for(int i=0; i<answer; i++){
        s.push(arr[max_node]);
        max_node = before[max_node];
    }
    cout << answer << "\n";
    for (int i = 0; i < answer; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}