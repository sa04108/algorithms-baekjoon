// BOJ GOLD 3
// https://www.acmicpc.net/problem/1644

#include <bits/stdc++.h>
using namespace std;

bool cn[4'000'001]; // composite number = not prime number
vector<int> pn;

int main() {
	int n; cin >> n;
	int rtn = sqrt(n);

	// sieve of eratosthenes
	for (int i = 2; i <= rtn; i++) {
		if (cn[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			cn[j] = true;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!cn[i]) pn.push_back(i);
	}

	// two pointer
	int s = 0, e = 0;
	int sum = 0;
	int ans = 0;

	while (1) {
		if (sum > n) {
			sum -= pn[s];
			s++;
		}
		else {
			if (sum == n) {
				ans++;
			}
			if (e >= pn.size()) break;
			sum += pn[e];
			e++;
		}
	}

	cout << ans;

	return 0;
}