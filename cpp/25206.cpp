#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string grade;
    double gradelev, score, totalgrade, totalscore;
    for (int i = 0; i < 20; i++)
    {
        cin >> name;
        cin >> score;
        cin >> grade;
        if (grade == "P")
            continue;
        else if (grade == "A+")
            gradelev = 4.5;
        else if (grade == "A0")
            gradelev = 4.0;
        else if (grade == "B+")
            gradelev = 3.5;
        else if (grade == "B0")
            gradelev = 3.0;
        else if (grade == "C+")
            gradelev = 2.5;
        else if (grade == "C0")
            gradelev = 2.0;
        else if (grade == "D+")
            gradelev = 1.5;
        else if (grade == "D0")
            gradelev = 1.0;
        else if (grade == "F")
            gradelev = 0;
        totalgrade += gradelev * score;
        totalscore += score;
    }
    cout << fixed;
    cout.precision(6);
    cout << totalgrade / totalscore;
}