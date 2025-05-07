#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9+1

long long n, m;

int sz = 100010;

int arr[100010];
pair<int,int> tree[400010];

pair<int,int> find_min(const pair<int,int> p1, const pair<int,int> p2){
    if(p1.first == p2.first){
        if(p1.second < p2.second){
            return p1;
        }
        else return p2;
    }
    else if(p1.first < p2.first) return p1;
    else return p2;
}

pair<int,int> query(long long left, long long right)
{
    left = left - 1 + sz;
    right = right - 1 + sz;
    pair<int,int> mn = {INF,INF};
    while (left <= right)
    {
        if (left % 2 == 1)
        {
            mn = find_min(tree[left],mn);
            left++;
        }
        if (right % 2 == 0)
        {
            mn = find_min(tree[right],mn);
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return mn;
}

void update(long long idx, long long value)
{
    int real_idx = idx;
    idx = idx - 1 + sz;
    tree[idx] = {value,real_idx};
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = find_min(tree[idx*2],tree[idx*2+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        update(i, arr[i]);
    }
    cin >> m;
    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 2){
            pair<int,int> temp = query(b,c);
            cout << temp.second << "\n";
        }
        else
            update(b, c);
    }
}