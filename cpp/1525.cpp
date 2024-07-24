#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

string str;
set<string> check;
int n;

int dx[4] = {1, -1, 3, -3};

int bfs()
{
    queue<pair<string, int>> q;
    q.push({str, 0});
    check.insert(str);
    while (!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == "123456780")
            return cnt;
        int i = cur.find('0');
        for (int j = 0; j < 4; j++)
        {
            int nx = i + dx[j];
            if (nx < 0 || nx >= n || (j <= 1 && i / 3 != nx / 3))
                continue;
            string next = cur;
            swap(next[i], next[nx]);
            if (check.find(next) == check.end())
            {
                check.insert(next);
                q.push({next, cnt + 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while (str.size() < 9)
    {
        char temp;
        cin >> temp;
        if (temp >= '0' && temp <= '9')
            str += temp;
    }
    n = 9;
    cout << bfs() << "\n";
}