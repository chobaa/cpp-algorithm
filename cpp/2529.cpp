#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check[10];
char order[10];
long long bigger = 0, smaller = 9999999999;
int n;

void compare(int before, int comp, long long answer)
{
    if (comp == n)
    {
        bigger = max(bigger, answer);
        smaller = min(smaller, answer);
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (!check[i])
        {
            if (order[comp] == '>' && before > i)
            {
                check[i] = true;
                compare(i, comp + 1, answer * 10 + i);
                check[i] = false;
            }
            if (order[comp] == '<' && before < i)
            {
                check[i] = true;
                compare(i, comp + 1, answer * 10 + i);
                check[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }
    for (int i = 0; i <= 9; i++)
    {
        check[i] = true;
        compare(i, 0, i);
        check[i] = false;
    }
    cout << bigger << "\n";
    if (to_string(smaller).length() != n + 1)
        cout << "0";
    cout << smaller << "\n";
}