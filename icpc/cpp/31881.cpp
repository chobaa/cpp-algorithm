#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispollution[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, answer = 0;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            if (!ispollution[b])
            {
                ispollution[b] = true;
                answer += 1;
            }
        }
        else if (a == 2)
        {
            cin >> b;
            if (ispollution[b])
            {
                ispollution[b] = false;
                answer -= 1;
            }
        }
        else
        {
            cout << n - answer << "\n";
        }
    }
}