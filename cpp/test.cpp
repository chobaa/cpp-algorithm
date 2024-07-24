#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (1)
    {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        int base = 1;
        while (base > n * 10)
        {
            if (cur - base == n || cur + base == n)
                return count + 1;
            else
            {
                q.push({cur - base, count + 1});
                q.push({cur + base, count + 1});
            }
            base *= 10;
        }
    }
}

int main()
{
    int answer = 0;
    answer = bfs(6);
    cout << answer;
}