#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> a[1001];
int p[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int idx = a[i].second;
        p[idx] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}