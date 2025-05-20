#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;

vector<int> in[200001];
vector<int> out[200001];
vector<int> isfriend[200001];
bool active[200001];

int answer[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        in[a].push_back(i);
        out[b].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        isfriend[a].push_back(b);
        isfriend[b].push_back(a);
    }
    int valid = 0;
    for (int i = 0; i < t; i++)
    {
        for(auto b : out[i]){
            active[b] = false;
            for(auto v : isfriend[b]){
                if(active[v]) valid--;
            }
        }
        for(auto a : in[i]){
            active[a] = true;
            for(auto v : isfriend[a]){
                if(active[v]) valid++;
            }
        }
        answer[i] = valid;
    }
    for (int i = 0; i < t; i++)
    {
        cout << answer[i] << "\n";
    }
}