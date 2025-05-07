#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> a; // original list
vector<int> b; // sum of two numbers from original list
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b.push_back(a[i] + a[j]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (binary_search(b.begin(), b.end(), a[i] - a[j]))
            {
                cout << a[i] << "\n";
                return 0;
            }
        }
    }
}