#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int result = 0, answer = 999999999;

int map[51][51];

int main()
{
    cin >> n >> m;
    vector<pair<int, int>> chicken;
    vector<pair<int, int>> candidate;
    candidate.resize(m);
    vector<bool> pm;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                chicken.push_back({i, j});
                pm.push_back(false);
            }
        }
    }
    fill(pm.end() - m, pm.end(), true);
    while (next_permutation(pm.begin(), pm.end()))
    {
        result = 0;
        int idx = 0;
        for (int i = 0; i < pm.size(); i++)
        {
            if (pm[i])
                candidate[idx++] = {chicken[i].first, chicken[i].second};
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 1)
                {
                    int dist = 999999999;
                    for (int k = 0; k < idx; k++)
                    {
                        int ny = candidate[k].first;
                        int nx = candidate[k].second;
                        int nd = abs(i - ny) + abs(j - nx);
                        dist = min(nd, dist);
                    }
                    result += dist;
                }
            }
        }
        answer = min(answer, result);
    }
    cout << answer;
}