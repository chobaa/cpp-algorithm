#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int box[2001];

vector<pair<int, pair<int, int>>> list;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, total, m;
    long long answer = 0;
    cin >> n >> total >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list.push_back({b, {a, c}});
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++)
    {
        int start = list[i].second.first;
        int end = list[i].first;
        int weight = list[i].second.second;
        int possible = weight;
        for (int j = start; j < end; j++)
        {
            possible = min(total - box[j], possible);
        }
        for (int j = start; j < end; j++)
        {
            box[j] += possible;
        }
        answer += possible;
    }
    cout << answer;
}