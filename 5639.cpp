#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void postorder(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else if (start == end - 1)
    {
        cout << v[start] << "\n";
        return;
    }
    int idx = start + 1;
    while (idx < end)
    {
        if (v[start] < v[idx])
            break;
        idx++;
    }
    postorder(start + 1, idx);
    postorder(idx, end);
    cout << v[start] << "\n";
    return;
}

int main()
{
    while (cin >> n)
    {
        v.push_back(n);
    }
    postorder(0, v.size());
}