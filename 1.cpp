#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 30001
#define MAX_K 15
using namespace std;

int N, M, a, b, pre = 1, now, ans = 0;
bool visit[MAX];
int dp[MAX][MAX_K];
vector<int> tree[MAX];
int depth[MAX], dist[MAX];

void dfs(int n, int d)
{
	depth[n] = d;	 // depth 저장
	visit[n] = true; // 방문
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i]; // 다음 방문할 node
		if (visit[next])
			continue;	  // 이미 방문한 경우
		dp[next][0] = n;  // 부모 정보 저장
		dfs(next, d + 1); // dfs 탐색
	}
}

void init()
{ // 2^k번째 조상까지 정보 저장
	for (int k = 1; k < MAX_K; k++)
	{
		for (int i = 1; i <= N; i++)
			dp[i][k] = dp[dp[i][k - 1]][k - 1];
	}
}

int lca(int x, int y)
{
	if (depth[y] < depth[x])
		swap(y, x); // y가 더 깊음을 보장
	for (int k = MAX_K - 1; k >= 0; k--)
	{ // x, y의 depth를 맞춤
		if (depth[y] - depth[x] >= 1 << k)
			y = dp[y][k];
	}
	if (x == y)
		return x; // x가 LCA(최소 공통 조상)인 경우
	for (int k = MAX_K - 1; k >= 0; k--)
	{ // LCA를 찾음
		if (dp[x][k] != dp[y][k])
		{
			x = dp[x][k];
			y = dp[y][k];
		}
	}
	return dp[x][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++)
	{ // tree를 만듦
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0); // depth, 부모노드 정보 저장
	init();	   // 2^k번째 조상까지의 정보 저장
	cin >> M;
	for (int i = 0; i < M; i++)
	{ // 한동이가 방문해야 할 모든 도시를 방문 할 수 있는 최소 시간을 구함
		cin >> now;
		ans += (depth[pre] + depth[now] - 2 * depth[lca(now, pre)]);
		pre = now;
	}
	cout << ans;
}