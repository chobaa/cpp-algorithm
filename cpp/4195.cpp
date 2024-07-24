#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> m;
vector<int> parent, num;

int result = 0;

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void union_parent(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y;
        num[y] += num[x];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    parent.resize(200001);
    num.resize(200001);
    int t;
    cin >> t;
    while (t--)
    {
        parent.clear();
        num.clear();
        m.clear();
        int f, idx = 1;
        cin >> f;
        for (int i = 0; i <= f * 2; i++)
        {
            parent[i] = i;
            num[i] = 1;
        }
        for (int i = 0; i < f; i++)
        {
            string str, str2;
            cin >> str >> str2;
            int str_idx, str2_idx;
            if (m[str] == 0)
            {
                str_idx = idx;
                m[str] = idx;
                idx++;
            }
            else
                str_idx = m[str];
            if (m[str2] == 0)
            {
                str2_idx = idx;
                m[str2] = idx;
                idx++;
            }
            else
                str2_idx = m[str2];

            union_parent(str_idx, str2_idx);
            cout << num[find(str_idx)] << "\n";
        }
    }
}