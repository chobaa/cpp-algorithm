#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> get_pi(vector<bool> clock2)
{
    vector<int> fail(360000, 0);
    int j = 0;
    for (int i = 1; i < clock2.size(); i++)
    {
        while (j > 0 && clock2[i] != clock2[j])
            j = clock2[j - 1];
        if (clock2[i] == clock2[j])
            fail[i] = ++j;
    }
    return fail;
}

string kmp(vector<bool> clock1, vector<bool> clock2)
{
    vector<int> fail = get_pi(clock2);
    int j = 0;

    for (int i = 0; i < clock1.size(); i++)
    {
        while (j > 0 && clock1[i] != clock2[j])
            j = fail[j - 1];
        if (clock1[i] == clock2[j])
        {
            if (j == clock2.size() - 1)
            {
                return "possible";
            }
            else
                j++;
        }
    }
    return "impossible";
}

int main()
{
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<bool> clock1(720000, 0);
    vector<bool> clock2(360000, 0);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        clock1[num] = clock1[360000 + num] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        clock2[num] = 1;
    }
    cout << kmp(clock1, clock2) << "\n";
}