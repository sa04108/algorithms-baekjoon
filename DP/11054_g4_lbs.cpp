// BOJ GOLD 4
// https://www.acmicpc.net/problem/11054

#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int lisArr[1000];
int ldsArr[1000];

// find longest increasing subsequence
int lis(int end) {
	if (lisArr[end] > 1) return lisArr[end];
	for (int i = 0; i <= end; i++) {
		lisArr[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				lisArr[i] = max(lisArr[i], lisArr[j] + 1);
			}
		}
	}
	return lisArr[end];
}

// find longest decreasing subsequence
int lds(int start, int end) {
	if (ldsArr[start] > 1) return ldsArr[start];
	for (int i = end; i >= start; i--) {
		ldsArr[i] = 1;
		for (int j = end; j > i; j--) {
			if (arr[i] > arr[j]) {
				ldsArr[i] = max(ldsArr[i], ldsArr[j] + 1);
			}
		}
	}
	return ldsArr[start];
}

// f[n] = max(a[0, 1] + d[1, n - 1] - 1, a[0, 2] + d[2, n - 1] - 1, ... , a[0, n - 2] + d[n - 2, n - 1] - 1)
int f(int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int val = lis(i) + lds(i, n - 1) - 1;
		if (max < val) max = val;
	}
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << f(n);

	return 0;
}