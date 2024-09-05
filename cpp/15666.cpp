#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
set<int> s;
vector<int> v;

void find_nm(int idx, vector<int> a)
{
    if (a.size() == m)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        a.push_back(v[i]);
        find_nm(i, a);
        a.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
    {
        v.push_back(*iter);
    }
    vector<int> a;
    find_nm(0, a);
}