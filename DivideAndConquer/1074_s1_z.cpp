// BOJ SILVER 1
// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>
using namespace std;

int dp(int x, int y, int n) {
	if (n == 0) return 0;

	int lim = 1 << n - 1;
	if (x < lim && y < lim)
		return dp(x, y, n - 1);
	else if (x >= lim && y < lim)
		return lim * lim * 1 + dp(x - lim, y, n - 1);
	else if (x < lim && y >= lim)
		return lim * lim * 2 + dp(x, y - lim, n - 1);
	else
		return lim * lim * 3 + dp(x - lim, y - lim, n - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << dp(c, r, n);
}