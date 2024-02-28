// BOJ GOLD 4
// https://www.acmicpc.net/problem/9663

#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
bool *col;
bool *col_l;
bool *col_r;

void dfs(int row) {
	if (row == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (col[i] || col_l[row + i] || col_r[row - i + n - 1]) // 대각선의 번호를 위에서부터 0이라 할때 각 대각선 번호가 정해지기 위한 x(i)와 y(row)의 함수
			continue;

		col[i] = col_l[row + i] = col_r[row - i + n - 1] = true;
		dfs(row + 1);
		col[i] = col_l[row + i] = col_r[row - i + n - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	col = new bool[n] { false, };
	col_l = new bool[2 * n - 1] { false, }; // n x n 보드에서 대각선 개수는 2n - 1개
	col_r = new bool[2 * n - 1] { false, }; // n x n 보드에서 대각선 개수는 2n - 1개

	dfs(0);
	cout << ans;

	delete[] col;
	delete[] col_l;
	delete[] col_r;

	return 0;
}