#include <iostream>

using namespace std;

int main()
{
    int totalprice, count, total = 0;
    cin >> totalprice >> count;
    for (int i = 0; i < count; i++)
    {
        int price, n;
        cin >> price >> n;
        total += price * n;
    }
    if (total == totalprice)
        cout << "Yes";
    else
        cout << "No";
}