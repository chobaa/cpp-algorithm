#include <iostream>
#include <vector>

using namespace std;

int n, m;
int psum[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << "\n";
    }
}