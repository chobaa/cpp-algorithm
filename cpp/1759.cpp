#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, c;
vector<char> v;

void check(int i, vector<char> answer, int moum, int jaum)
{
    if (i >= c)
    {
        if (i == c && jaum >= 2 && moum >= 1 && (int)answer.size() == c)
        {
            for (int i = 0; i < (int)answer.size(); i++)
            {
                cout << answer[i];
            }
            cout << "\n";
        }
        return;
    }
    for (int j = i; j < n; j++)
    {

        if (v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u')
        {
            if (answer.empty() || v[j] > answer[answer.size() - 1])
            {
                answer.push_back(v[j]);
                check(i + 1, answer, moum + 1, jaum);
                answer.pop_back();
            }
        }
        else if (answer.empty() || v[j] > answer[answer.size() - 1])
        {
            answer.push_back(v[j]);
            check(i + 1, answer, moum, jaum + 1);
            answer.pop_back();
        }
    }
}

int main()
{
    cin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n - c; i++)
    {
        vector<char> answer;
        check(i, answer, 0, 0);
    }
}