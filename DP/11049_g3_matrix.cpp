// BOJ GOLD 3
// https://www.acmicpc.net/problem/11049

#include <bits/stdc++.h>
using namespace std;

int n;
int r[501], c[501];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> c[i];
	}
	
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len; i++) {
			dp[i][i + len] = 1e9;
			for (int pin = i; pin < i + len; pin++) {
				dp[i][i + len] = min(dp[i][i + len], dp[i][pin] + dp[pin + 1][i + len] + r[i] * c[pin] * c[i + len]);
			}
		}
	}

	cout << dp[1][n];
}