#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> lecture;
bool possible[100001];

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lecture.push_back({a, b});
    }
    sort(lecture.begin(), lecture.end(), cmp);
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = lecture[i].second;
        while(idx >= 1 && possible[idx]) idx--;
        if(idx == 0) continue;
        else{
            answer += lecture[i].first;
            possible[idx] = true;
        }
    }
    cout << answer;
}