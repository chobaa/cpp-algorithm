#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int loc[200001];
int arr[200001];
int tree[800001];
int idx = 0;

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, int diff)
{
    if (idx > end || idx < start)
        return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}

int sum(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 0;
    if (left <= start && right >= end)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    /*
    loc배열에는 각 dvd의 위치를 담고있음. 시작 위치는 k+i에서 시작하고,
    이동한 dvd를 지워주고 k,k-1,k-2... 순으로 채움
    이동한 후 기존 자리는 0으로 바뀌고,
    각 sum을 구할때는 자신보다 하나 위부터 몇개가 쌓여있는지 계산하면 됨.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n + k; i++)
        {
            tree[i] = 0;
            arr[i] = 0;
            loc[i] = 0;
        }
        idx = k;
        for (int i = 1; i <= n; i++)
        {
            arr[k + i] = 1;
            loc[i] = i + k;
        }
        init(1, n + k, 1);
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            cout << sum(1, n + k, 1, idx, loc[temp] - 1) << " "; // loc[temp]-1인 이유, 자기 자신 위까지의 합이 깔려있는 갯수
            update(1, n + k, 1, loc[temp], -1);
            update(1, n + k, 1, idx, 1);
            loc[temp] = idx;
            idx--;
        }
        cout << "\n";
    }
}