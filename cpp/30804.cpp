#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;
    deque<int> d;
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        d.push_back(temp);
        m[temp]++;
        s.insert(temp);
        while (s.size() > 2)
        {
            int head = d.front();
            d.pop_front();
            m[head]--;
            if (m[head] == 0)
                s.erase(head);
        }
        if (answer < d.size())
            answer = d.size();
    }
    cout << answer;
}