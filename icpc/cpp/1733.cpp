#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int shirt[1000001][2];
vector<pair<int, int>> graph[1000001];
int cnt[1000001];
bool chk[1000001];
int answer[1000001];
queue<int> q;

void dfs(int x)
{
    // 비어있는 칸에 가능한 것을 먼저 넣음
    for (auto i : graph[x])
    {
        // cnt == 0일 경우 두 가지 경우 중 한 가지를 이미 넣은 경우임.
        if (cnt[i.first] == 0)
            continue;
        // 0이 아닐 경우 일단 한 가지를 결정 짓고, 나머지 탐색을 이어나감.
        cnt[i.first] = 0;
        answer[i.second] = x;
        chk[x] = true;
        dfs(i.first);
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> shirt[i][0] >> shirt[i][1];
        graph[shirt[i][0]].push_back({shirt[i][1], i});
        graph[shirt[i][1]].push_back({shirt[i][0], i});
        cnt[shirt[i][0]]++;
        cnt[shirt[i][1]]++;
    }
    for (int i = 1; i < 1000001; i++)
    {
        if (cnt[i] == 1)
            q.push(i);
    }
    // 자리에 들어갈 경우의 수가 1개인 것 먼저 매칭
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto s : graph[now])
        {
            if (answer[s.second] != 0)
                continue;
            cnt[now]--;
            cnt[s.first]--;
            // 하나의 자리가 정해짐으로써 경우의 수가 줄어 1개가 될 경우 매칭시켜줌
            if (cnt[s.first] == 1)
            {
                q.push(s.first);
            }
            answer[s.second] = now;
            chk[now] = true;
            break;
        }
    }
    for (int i = 1; i < 1000001; i++)
    {
        // 2보다 큰 경우 V < E인 경우이기 떄문에 연결 불가능
        if (cnt[i] > 2)
        {
            cout << -1;
            return 0;
        }
        if (cnt[i] == 2)
        {
            cnt[i] = 0;
            dfs(i);
        }
    }
    // 아까 경우의 수는 좁혀졌지만 넣지 못한 것들 중, 겹치는 것이 없다면 pass, 겹치는 것이 있으면 불가능한 경우이다.
    for (int i = 1; i <= n; i++)
    {
        if (answer[i] != 0)
            continue;
        if (!chk[shirt[i][0]])
        {
            answer[i] = shirt[i][0];
            chk[shirt[i][0]] = true;
        }
        else if (!chk[shirt[i][1]])
        {
            answer[i] = shirt[i][1];
            chk[shirt[i][1]] = true;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << "\n";
    }
}