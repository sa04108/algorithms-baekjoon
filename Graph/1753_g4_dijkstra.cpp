// BOJ GOLD 4
// https://www.acmicpc.net/problem/1753

#include <bits/stdc++.h>
using namespace std;

#define INF 1e9+7
using pint = pair<int, int>;

vector<pair<int, int>> graph[20'001];
priority_queue<pint, vector<pint>, greater<pint>> pq;
int dist[20'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int v, e, s; cin >> v >> e >> s;
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    fill(dist, dist + v + 1, INF);

    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto vp = pq.top(); pq.pop();
        if (vp.first != dist[vp.second]) continue;

        int w = vp.first;
        int cv = vp.second;
        for (int i = 0; i < (int)graph[cv].size(); i++) {
            int nv = graph[cv][i].first;
            int nw = graph[cv][i].second;
            if (dist[nv] > dist[cv] + nw) {
                dist[nv] = dist[cv] + nw;
                pq.push({dist[nv], nv});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << '\n';
    }

    return 0;
}
