#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int psum[100001];
int answer = 0;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }
    int before_min = 0;
    for (int i = m; i <= n; i++)
    {
        before_min = min(psum[i - m], before_min);
        answer = max(answer, psum[i] - before_min);
    }
    if (answer < 0)
        cout << 0;
    else
        cout << answer;
}