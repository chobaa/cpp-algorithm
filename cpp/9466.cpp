#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
bool visited[100001];
bool done[100001];

int cnt = 0;

void check_cycle(int x)
{
    visited[x] = true;
    int next = arr[x];
    if (!visited[next])
        check_cycle(next);
    else if (!done[next])
    {
        for (int i = next; i != x; i = arr[i])
            cnt++;
        cnt++;
    }
    done[x] = true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            done[i] = false;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                check_cycle(i);
        }
        cout << n - cnt << "\n";
    }
}