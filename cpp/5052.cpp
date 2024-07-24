#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool correct = true;
        int n;
        cin >> n;
        vector<string> list;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            list.push_back(str);
        }

        sort(list.begin(), list.end());

        for (int i = 0; i < list.size() - 1; i++)
        {
            int cur_len = list[i].length();
            int next_len = list[i + 1].length();
            if (cur_len >= next_len)
                continue;
            else if (list[i] == list[i + 1].substr(0, cur_len))
            {
                correct = false;
                cout << "NO"
                     << "\n";
                break;
            }
        }

        if (correct)
            cout << "YES"
                 << "\n";
    }
}