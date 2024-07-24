#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push_back(temp);
    }
    sort(q.begin(), q.end());
    int front = q.front();
    int back = q.back();
    q.pop_back();
    q.pop_front();
    int diff = abs(front + back);
    int top_front = front;
    int top_back = back;
    while (!q.empty())
    {
        if (abs(front + back) < diff)
        {
            diff = abs(front + back);
            top_front = front;
            top_back = back;
        }
        else if (abs(front + back) >= 0)
        {
            back = q.back();
            q.pop_back();
        }
        else
        {
            front = q.front();
            q.pop_front();
        }
    }
    if (top_front < top_back)
        cout << top_front << " " << top_back;
    else
        cout << top_back << " " << top_front;
}