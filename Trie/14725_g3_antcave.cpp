// BOJ GOLD 3
// https://www.acmicpc.net/problem/14725

#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool fin;
	map<string, Trie*> m;

public:
	void insert(vector<string>& str, int i) {
		if (i == str.size()) {
			fin = true;
			return;
		}

		Trie* target;
		auto mit = m.find(str[i]);
		if (mit == m.end()) {
			target = new Trie();
			m.insert(make_pair(str[i], target)).second;
		}
		else
			target = mit->second;
		target->insert(str, i + 1);
	}

	bool find(vector<string>& str, int i) {
		if (i == str.size()) {
			if (fin) return true;
			return false;
		}
		
		auto mit = m.find(str[i]);
		if (mit == m.end()) return false;
		return mit->second->find(str, i + 1);
	}

	void dfs(int depth) {
		if (fin) true;
		for (auto it = m.begin(); it != m.end(); it++) {
			for (int j = 0; j < depth; j++)
				cout << "--";
			cout << it->first << '\n';
			it->second->dfs(depth + 1);
		}
	}
};

int main() {
	int n;
	cin >> n;

	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		vector<string> str;
		for (int j = 0; j < k; j++) {
			char s[15];
			cin >> s;
			str.push_back(s);
		}
		root->insert(str, 0);
	}

	root->dfs(0);

	delete root;
}