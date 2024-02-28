// BOJ GOLD 3
// https://www.acmicpc.net/problem/1005

#include <bits/stdc++.h>
using namespace std;

int buildtime[1001];
int indegree[1001];
int memo[1001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> graph(n + 1);
		
		for (int i = 0; i < n; i++) {
			cin >> buildtime[i + 1];
			memo[i + 1] = buildtime[i + 1];
		}
		for (int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		
		int target; cin >> target;
		
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int& next : graph[cur]) {
				memo[next] = max(memo[next], memo[cur] + buildtime[next]);
				if (--indegree[next] == 0) {
					q.push(next);
				}
			}
		}
		
		memset(buildtime, 0, sizeof(buildtime));
		memset(indegree, 0, sizeof(indegree));
		
		cout << memo[target] << '\n';
	}
	return 0;
}