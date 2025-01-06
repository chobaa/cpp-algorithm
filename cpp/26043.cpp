#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> pass;
vector<int> half;
vector<int> fail;

int main()
{
    int n;
    cin >> n;
    int menu1 = 0, menu2 = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            q.push({a, b});
        }
        if (op == 2)
        {
            int temp;
            cin >> temp;
            int person = q.front().first;
            int menu = q.front().second;
            q.pop();
            if(temp == menu) pass.push_back(person);
            else if(temp != menu) half.push_back(person);
        }
    }
    while(!q.empty()){
        int person = q.front().first;
        int menu = q.front().second;
        q.pop();
        fail.push_back(person);
    }

    sort(pass.begin(), pass.end());
    sort(half.begin(), half.end());
    sort(fail.begin(), fail.end());

    if (pass.size() == 0)
        cout << "None";
    for (int i = 0; i < pass.size(); i++)
    {
        cout << pass[i] << " ";
    }
    cout << "\n";

    if (half.size() == 0)
        cout << "None";
    for (int i = 0; i < half.size(); i++)
    {
        cout << half[i] << " ";
    }
    cout << "\n";

    if (fail.size() == 0)
        cout << "None";
    for (int i = 0; i < fail.size(); i++)
    {
        cout << fail[i] << " ";
    }
    cout << "\n";
}