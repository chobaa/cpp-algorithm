#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> s1;
vector<char> s2;

int table[1000001];
int answer = 0;
int n;

void get_pi()
{
    int j = 0;
    for (int i = 1; i < s2.size(); i++)
    {
        while (j > 0 && s2[i] != s2[j])
            j = table[j - 1];
        if (s2[i] == s2[j])
            table[i] = ++j;
    }
}

void kmp()
{
    get_pi();
    int j = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        while (j > 0 && s1[i] != s2[j])
            j = table[j - 1];
        if (s1[i] == s2[j])
        {
            j++;
            if (j == n)
            {
                answer++;
                j = table[j - 1];
            }
        }
    }
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp;
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        s1.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        s2.push_back(temp);
        s1.push_back(s1[i]);
    }
    s1.pop_back();
    kmp();
    int g = gcd(answer, n);
    cout << answer / g << "/" << n / g;
}