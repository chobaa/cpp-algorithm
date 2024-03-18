#include <iostream>
#include <algorithm>

using namespace std;
int n,ts,m;
int ans;
typedef pair<pair<int, int>, int> p;

bool cmp(p a, p b) {
    return a.first.second < b.first.second;
}

int main() {
    cin >> n >> ts >> m;
    vector<p> arr;
    vector<int> truck(n);

    for(int i=0 ; i<m ; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        arr.push_back(p(make_pair(a, b), c));
    }
    sort(arr.begin(), arr.end(), cmp);
    
    int size = arr.size();
    for(int i=0 ; i<size ; i++) {
        int start = arr[i].first.first-1;
        int end = arr[i].first.second-1;
        int box = arr[i].second;
        int temp=0;
        int cnt=0;

        for(int j=start ; j<end ; j++) {
            temp = max(temp, truck[j]); // 해당하는 마을에서 쌓인 박스 수 중 가장 큰 수
        }
        if(temp+box<=ts) cnt = box; // 가장 큰 수에 박스를 넣어도 용량을 안넘으면
        else cnt = ts-temp; // 용량을 넘으면

        for(int j=start ; j<end ; j++) {
            truck[j] += cnt;
        }
        ans += cnt;
    }

    cout << ans << "\n";

    return 0;
}