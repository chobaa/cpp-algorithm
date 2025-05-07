#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, Q, cmd, a, b, idx;
vector<ll> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;

    A = vector<ll>(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    while (Q--)
    {
        cin >> cmd >> a;
        if (cmd == 3)
        {
            cin >> b;

            a = (a - 1 + idx) % N;
            b = (b - 1 + idx) % N;

            if (a <= b) // 안쪽 범위
            {
                cout << A[b + 1] - A[a];
            }
            else // 바깥쪽 범위
            {
                cout << A[N] - A[0] - (A[a] - A[b + 1]);
            }
            cout << "\n";
        }
        else
        {
            idx += ((cmd == 1) ? -a : a);
            idx = (idx + N) % N;
        }
    }
    return 0;
}