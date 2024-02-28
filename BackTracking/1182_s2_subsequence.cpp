// BOJ SILVER 2
// https://www.acmicpc.net/problem/1182

#include <bits/stdc++.h>
using namespace std;

int n, s, ans;
int arr[21];

void dfs(int cur, int sum) {
	if (cur == n) {
		if (sum == s) ans++;
		return;
	}
	
	dfs(cur + 1, sum);
	dfs(cur + 1, sum + arr[cur]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dfs(0, 0);
	if (s == 0) ans--; // except empty set
	cout << ans;
}