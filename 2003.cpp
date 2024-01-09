#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, key, answer = 0;
    cin >> n >> key;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(temp);
    }
    int total = 0;
    auto iter = dq.begin();
    while (!dq.empty())
    {
        if (total >= key)
        {
            if (total == key)
                answer++;
            total -= dq.front();
            dq.pop_front();
        }
        else if (iter != dq.end())
        {
            total += *iter++;
        }
        else
        {
            break;
        }
    }

    cout << answer;
}