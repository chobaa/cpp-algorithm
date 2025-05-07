#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> list;
int max = 0;

void seperate_list(int current_min, int left, int right)
{
    int finded = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == current_min)
        {
            int cnt = 1;
            int idx = i + 1;
            while (list[idx] == current_min)
            {
                cnt += 1;
                idx += 1;
            }
            int diff = idx - i;
            if (diff % 2 == 0)
            {
                int padding = 0;
                for (int t = i; t < idx; t += 2)
                {
                    list.erase(list.begin() + i + padding);
                    list.erase(list.begin() + i + padding);
                    list.insert(list.begin() + i + padding, current_min + 1);
                    padding += 1;
                }
            }
            else
            {
                diff /= 2;
                seperate_list(current_min, left, i + diff)
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    seperate_list(1, 0, n - 1);
}