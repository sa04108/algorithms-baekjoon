// BOJ SILVER 2
// https://www.acmicpc.net/problem/1654

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k, n;
	int arr[10001];
	cin >> k >> n;
	long long low, high, mid;
	low = 1; high = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (high < arr[i]) high = arr[i];
	}

	int ans = 0;
	while (low <= high) {
		mid = (low + high) * 0.5;
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += arr[i] / mid;
		if (cnt >= n) {
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else
			high = mid - 1;
	}
	cout << ans;
}