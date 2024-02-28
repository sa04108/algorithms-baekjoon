// BOJ GOLD 3
// https://www.acmicpc.net/problem/11066

#include <bits/stdc++.h>
using namespace std;

int n, a;
int dp[501][501];
int sum[501];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sum[0] = 0;
    int t;
    cin >> t;
    for (int ca = 0; ca < t; ca++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                dp[j][j + i] = 1e9;
                for (int pin = j; pin < j + i; pin++) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][pin] + dp[pin + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
    return 0;
}