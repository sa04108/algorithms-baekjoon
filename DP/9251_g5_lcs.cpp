// BOJ GOLD 5
// https://www.acmicpc.net/problem/9251

#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int dp[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[s1.size()][s2.size()];
}