#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> list;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        list[str] = 1;
    }
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (list[str] == 1)
            answer += 1;
    }

    cout << answer;
}