#include <iostream>

using namespace std;

int main()
{
    long long finger, count, current = 1, answer = 0, adder = 1;
    cin >> finger >> count;
    if (finger >= 2 && finger < 5 && count > 4)
    {
        if (count % 2 == 0)
        {
            answer = (count - 4) / 2 * 8;
            count = 4;
        }
        else if (count > 4)
        {
            answer = (count - 3) / 2 * 8;
            count = 3;
        }
    }
    else
    {
        answer += (count - 3) * 8;
        count = 3;
    }
    while (1)
    {
        if (finger == current)
        {
            if (count == 0)
                break;
            else
                count--;
        }
        if (current == 5)
            adder = -1;
        else if (current == 1)
            adder = 1;
        current += adder;
        answer++;
    }
    cout << answer;
}
