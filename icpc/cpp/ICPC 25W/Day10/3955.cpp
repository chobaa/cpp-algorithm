#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long,long long> eed(long long a, long long b)
{
    long long r0 = a, r1 = b;
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;
    long long tmp;
    while(r1 != 0){
        long long q = r0/r1;
			
        tmp = r0 - q*r1;
        r0 = r1;
        r1 = tmp;
        
        tmp = s0 - q*s1;
        s0 = s1;
        s1 = tmp;
        
        tmp = t0 - q*t1;
        t0 = t1;
        t1 = tmp;
    }
    return make_pair(t0,r0);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b;
        cin >> a >> b;
        pair<long long,long long> answer = eed(a, b);
        if (answer.second != 1) cout << "IMPOSSIBLE\n";
        else{
            long long t0 = answer.first;
            t0 = (t0%a+a) %a;
            t0 = max(t0,(a+b)/b);
            if(t0 <= 1e9) cout << t0 << "\n";
            else cout << "IMPOSSIBLE\n";
        }
    }
}