// modular 연산으로 풀이, 나머지가 같은 것끼리 묶고 조합으로 경우의 수 구하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long mod[1001];
long long answer = 0, psum = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        psum += temp;
        mod[psum % m]++;
    }
    for (int i = 0; i <= m; i++)
    {
        answer += (mod[i] * (mod[i] - 1)) / 2;
    }
    cout << answer + mod[0];
}

/* segment tree로 풀려고 시도했지만 사실 누적합을 모든 경우의 수로 연산한것과 비슷해서 실패
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[4000001];
int arr[1000001];

int n, m;

int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (sum(1, n, 1, i, j) % m == 0)
                answer++;
        }
    }
    cout << answer;
}
*/