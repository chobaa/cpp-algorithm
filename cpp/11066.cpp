#include <bits/stdc++.h>
using namespace std;
int tc, n, a[505], psum[505], dp[505][505];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) { // 길이
            for (int j = 1; j + i <= n; j++) { // 인덱스
                dp[j][i + j] = 1e9;
                int sum = psum[i + j] - psum[j - 1];
                for (int k = j; k < i + j; k++) {
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum);
                }
            }
        }
        cout << dp[1][n] << '\n';
    }
}