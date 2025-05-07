#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(long long a, long long b)
{
    queue<pair<long long, int>> q;
    q.push({a, 1});
    while (!q.empty())
    {
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == b)
            return cnt;
        if (cur * 10 + 1 <= 1e9)
        {
            q.push({cur * 10 + 1, cnt + 1});
        }
        if (cur * 2 <= 1e9)
        {
            q.push({cur * 2, cnt + 1});
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    cout << bfs(a, b);
}