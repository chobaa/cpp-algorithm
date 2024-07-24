#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<char, int> a, const pair<char, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<string> word;
    map<char, int> score;
    for (int i = 0; i < n; i++)
    {
        int multiple = 1;
        string temp;
        cin >> temp;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            score[temp[i]] += multiple;
            multiple *= 10;
        }
        word.push_back(temp);
    }
    vector<pair<char, int>> score2;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (score[i] != 0)
            score2.push_back({i, score[i]});
    }
    int a = 9;
    sort(score2.begin(), score2.end(), cmp);
    for (auto value : score2)
    {
        if (value.second != 0)
        {
            score[value.first] = a--;
        }
        else
            score[value.first] = -1;
    }
    int answer = 0;
    for (auto str : word)
    {
        int multiple = 1;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            answer += score[str[i]] * multiple;
            multiple *= 10;
        }
    }

    cout << answer;
}