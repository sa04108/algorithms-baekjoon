// BOJ GOLD 5
// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string f;
		int n;
		string s;
		deque<int> deq;
		cin >> f >> n >> s;
		int pin = 0;
		if (s.length() > 2) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == ',' || s[i] == ']') {
					deq.push_back(stoi(s.substr(pin + 1, i - pin - 1)));
					pin = i;
				}
			}
		}

		bool reversed = false;
		bool error = false;
		for (int i = 0; i < f.length(); i++) {
			if (f[i] == 'D') {
				if (deq.empty()) {
					cout << "error";
					error = true;
					break;
				}
				if (reversed)
					deq.pop_back();
				else
					deq.pop_front();
			}
			else if (f[i] == 'R') {
				if (i + 1 < f.length() && f[i + 1] == 'R') {
					i++;
					continue;
				}
				reversed = !reversed;
			}
		}

		if (!error) {
			cout << '[';
			if (!deq.empty()) {
				if (reversed) {
					for (int i = deq.size() - 1; i >= 0; i--) {
						cout << deq[i];
						if (i > 0) cout << ',';
					}
				}
				else {
					for (int i = 0; i < deq.size(); i++) {
						cout << deq[i];
						if (i < deq.size() - 1) cout << ',';
					}
				}
			}
			cout << ']';
		}

		cout << '\n';
	}
}