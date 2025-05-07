#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long t, n, m;
    cin >> t >> n;
    vector<long long> a(n);
    vector<long long> sum_a;
    vector<long long> sum_b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        long long psum_a = a[i];
        sum_a.push_back(psum_a);
        for (int j = i + 1; j < n; j++)
        {
            psum_a += a[j];
            sum_a.push_back(psum_a);
        }
    }

    for (int i = 0; i < m; i++)
    {
        long long psum_b = b[i];
        sum_b.push_back(psum_b);
        for (int j = i + 1; j < m; j++)
        {
            psum_b += b[j];
            sum_b.push_back(psum_b);
        }
    }

    sort(sum_a.begin(), sum_a.end());
    sort(sum_b.begin(), sum_b.end());

    int result = 0;
    for (int i = 0; i < sum_a.size(); i++)
    {
        int low = lower_bound(sum_b.begin(), sum_b.end(), t - sum_a[i]) - sum_b.begin();
        int high = upper_bound(sum_b.begin(), sum_b.end(), t - sum_a[i]) - sum_b.begin();
        result += high - low;
    }
    cout << result;
}