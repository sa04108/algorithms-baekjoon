// BOJ GOLD 4
// https://www.acmicpc.net/problem/1197

#include <bits/stdc++.h>
using namespace std;

int parent[10001];
int getParent(int v) {
	if (parent[v] == v) return v;
	return getParent(parent[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, pair<int, int>>> graph;
	int v, e;
	int ans = 0;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, {a, b} });
	}

	sort(graph.begin(), graph.end()); // sort by weight

	for (int i = 0; i < e; i++) {
		int v1 = getParent(graph[i].second.first);
		int v2 = getParent(graph[i].second.second);
		if (v1 == v2) continue; // union find
		if (v1 > v2) parent[v1] = v2;
		else parent[v2] = v1;
		ans += graph[i].first;
	}
	
	cout << ans;

}