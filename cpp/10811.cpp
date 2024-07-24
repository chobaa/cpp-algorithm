#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    for (int j = 0; j < m; j++)
    {
        int start, end, count = 0, t_start, t_end;
        ;
        cin >> start >> end;
        while (1)
        {
            t_start = start + count - 1;
            t_end = end - count - 1;
            if (t_start >= t_end)
            {
                count = 0;
                break;
            }
            else
                swap(v[t_start], v[t_end]);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}