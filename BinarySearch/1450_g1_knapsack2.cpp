// BOJ GOLD 1
// https://www.acmicpc.net/problem/1450

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[31];
vector<ll> va;
vector<ll> vb;

void dfs(ll sum, ll left, ll right, vector<ll>& vec) {
	if (left > right) {
		vec.push_back(sum);
		return;
	}
	else {
		dfs(sum, left + 1, right, vec); // neglect current value
		dfs(sum + arr[left], left + 1, right, vec); // add current value
	}
}

int main() {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    
    ll n, c;
    cin >> n >> c;
    for (ll i = 0; i < n; i++) {
    	cin >> arr[i];
	}
	
	dfs(0, 0, n / 2 - 1, va);
	dfs(0, n / 2, n - 1, vb);
	
	sort(vb.begin(), vb.end());
	
	ll ans = 0;
	for (ll& li : va) {
		ll rest = c - li;
		ans += upper_bound(vb.begin(), vb.end(), rest) - vb.begin();
	}
	
	cout << ans;
    
	return 0;
}