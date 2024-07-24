#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> positive;
vector<int> negative;
int zero = 0;

int main()
{
    int n;
    int answer = 0;
    int pos_num = 0;
    int neg_num = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            positive.push_back(temp);
            pos_num++;
        }
        if (temp < 0)
        {
            negative.push_back(temp);
            neg_num++;
        }
        if (temp == 0)
            zero++;
    }
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());
    for (int i = 0; i < pos_num - 1; i += 2)
    {
        if (positive[i] == 1 || positive[i + 1] == 1)
            answer += positive[i] + positive[i + 1];
        else
            answer += positive[i] * positive[i + 1];
    }
    if (pos_num % 2 != 0)
        answer += positive[pos_num - 1];

    for (int i = 0; i < neg_num - 1; i += 2)
    {
        answer += negative[i] * negative[i + 1];
    }

    if (neg_num % 2 != 0 && zero == 0)
        answer += negative[neg_num - 1];

    cout << answer;
}