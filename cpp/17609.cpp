#include <iostream>
#include <string>

using namespace std;

int answer;

void confirm(string str, int left, int right, int chance)
{
    while (left < right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else if (chance && str[left + 1] == str[right] && str[left] == str[right - 1])
        {
            confirm(str, left + 1, right, 0);
            confirm(str, left, right - 1, 0);
            return;
        }
        else if (chance && str[left + 1] == str[right])
        {
            left++;
            chance--;
        }
        else if (chance && str[left] == str[right - 1])
        {
            right--;
            chance--;
        }
        else
        {
            answer = min(answer, 2);
            return;
        }
    }
    if (chance == 0 && left >= right)
    {
        answer = min(answer, 1);
        return;
    }
    answer = min(answer, 0);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        answer = 3;
        confirm(str, 0, str.size() - 1, 1);
        cout << answer << "\n";
    }
}