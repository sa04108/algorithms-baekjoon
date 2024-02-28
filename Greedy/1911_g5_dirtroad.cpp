// BOJ GOLD 5
// https://www.acmicpc.net/problem/1911

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, l;
    vector<pair<int, int>> v;
    
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
    	int a, b; cin >> a >> b;
    	v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	int idx = v.front().first;
	
	for (pair<int, int>& p : v) {
		if (idx < p.first) idx = p.first;
		if (idx < p.second) {
			int step = (p.second - idx - 1) / l + 1; // = ceiling
			ans += step;
			idx += l * step;
		}
	}
	
	cout << ans;
    
	return 0;
}