#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, key, answer = 0, minimum = 100001;
    cin >> n >> key;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(temp);
    }
    int total = 0;
    int count = 0;
    auto iter = dq.begin();
    while (!dq.empty())
    {
        if (total >= key)
        {
            if (total == key)
            {
                answer++;
                if (minimum > count)
                    minimum = count;
            }
            total -= dq.front();
            dq.pop_front();
            count--;
        }
        else if (iter != dq.end())
        {
            total += *iter++;
            count++;
        }
        else
        {
            break;
        }
    }
    if (answer == 0)
        count = 0;

    cout << count;
}