#include <iostream>
#include <vector>

using namespace std;

long long psum[400001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, rotate = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
        psum[i + n] = psum[i];
    }
    for (int i = 1; i <= n; i++)
    {
        psum[i + n] += psum[n];
    }
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
            rotate = (rotate - b + n) % n;
        if (a == 2)
            rotate = (rotate + b + n) % n;
        if (a == 3)
        {
            cin >> c;
            int diff = c - b;
            b = (b + rotate + n) % n;
            if (b == 0)
                b = n;
            c = b + diff;
            cout << psum[c] - psum[b - 1] << "\n";
        }
    }
}