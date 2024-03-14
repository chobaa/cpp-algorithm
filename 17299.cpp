#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n;
int arr[1000001];
int cnt[1000001];
int ngf[1000001];
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    memset(ngf, -1, sizeof(ngf));
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && cnt[arr[st.top()]] < cnt[arr[i]])
        {
            ngf[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ngf[i] << " ";
    }
    cout << "\n";
}