// BOJ SILVER 1
// https://www.acmicpc.net/problem/1931

#include <bits/stdc++.h>
using namespace std;

bool predicate(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<int, int>> p;
	int t = 0, ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int f, s;
		cin >> f >> s;
		p.push_back(make_pair(f, s));

	}

	sort(p.begin(), p.end(), predicate);

	for (int i = 0; i < n; i++) {
		if (t <= p[i].first) {
			t = p[i].second;
			ans++;
		}
	}

	cout << ans;

	return 0;
}