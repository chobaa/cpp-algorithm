#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int number[1000001];
int card[1000001];
int score[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
        card[number[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = number[i] * 2; j < 1000001; j += number[i])
        {
            if (card[j] == 1)
            {
                score[number[i]]++;
                score[j]--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << score[number[i]] << " ";
    }
}