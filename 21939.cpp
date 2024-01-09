#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

struct cmp2
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq_max;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq_min;

vector<int> pos[100001];

int n, m;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pos[a].push_back(b);
        pq_max.push({a, b});
        pq_min.push({a, b});
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int a, b;
            cin >> a >> b;
            pos[a].push_back(b);
            pq_max.push({a, b});
            pq_min.push({a, b});
        }
        else if (str == "recommend")
        {
            int a;
            bool ispassed = false;
            cin >> a;
            if (a == 1)
            {
                while (!pq_max.empty() && !ispassed)
                {
                    pair<int, int> x = pq_max.top();
                    for (int i = 0; i < pos[x.first].size(); i++)
                    {
                        if (pos[x.first][i] == x.second)
                        {
                            cout << x.first << "\n";
                            ispassed = true;
                            break;
                        }
                    }
                    if (!ispassed)
                        pq_max.pop();
                }
            }
            else if (a == -1)
            {
                while (!pq_min.empty() && !ispassed)
                {
                    pair<int, int> x = pq_min.top();
                    for (int i = 0; i < pos[x.first].size(); i++)
                    {
                        if (pos[x.first][i] == x.second)
                        {
                            cout << x.first << "\n";
                            ispassed = true;
                            break;
                        }
                    }
                    if (!ispassed)
                        pq_min.pop();
                }
            }
        }
        else if (str == "solved")
        {
            int a;
            cin >> a;
            pos[a].clear();
        }
    }
}