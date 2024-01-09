#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> people;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int n, score = 999;
        cin >> n;
        if (n > 32)
        {
            cout << 0 << "\n";
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                string s;
                cin >> s;
                people.push_back(s);
            }
            for (int start = 0; start < n - 2; start++)
            {
                for (int second = start + 1; second < n - 1; second++)
                {
                    for (int third = second + 1; third < n; third++)
                    {
                        int small_score = 0;
                        for (int t = 0; t < 4; t++)
                        {
                            if (people[start][t] != people[second][t])
                                small_score++;
                            if (people[start][t] != people[third][t])
                                small_score++;
                            if (people[second][t] != people[third][t])
                                small_score++;
                        }
                        score = min(score, small_score);
                    }
                }
            }
            cout << score << "\n";
            people.clear();
            score = 999;
        }
    }
}