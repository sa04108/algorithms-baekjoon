// BOJ GOLD 5
// https://www.acmicpc.net/problem/12865

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	int w[100], v[100];

	cin >> n >> k;
	int** d = new int* [n];

	for (int i = 0; i < n; i++) {
		d[i] = new int[k + 1]{ 0, };
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0) d[i][j] = j < w[i] ? 0 : v[i];
			else d[i][j] = j < w[i] ? d[i - 1][j] : max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << d[n - 1][k];

	for (int i = 0; i < n; i++) {
		delete[] d[i];
	}
	delete[] d;

	return 0;
}