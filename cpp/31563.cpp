#include <iostream>
#include <vector>

using namespace std;

long long sum[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, rotate;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    for (int i = 0; i < q; i++)
    {
        int op, a, b;
        cin >> op >> a;
        if (op == 3)
        {
            cin >> b;
            a = (a - 1+ rotate) % n;
            b = (b - 1+ rotate) % n;
            if(a <= b){
                cout << sum[b+1] - sum[a] << "\n";
            }
            else{
                cout << sum[n] + sum[b+1] - sum[a] << "\n";
            }
        }
        else if (op == 1)
        {
            rotate = (rotate + n - a) % n;
        }
        else if (op == 2)
        {
            rotate = (rotate + a) % n;
        }
    }
}