// BOJ GOLD 2
// https://www.acmicpc.net/problem/11780

#include <bits/stdc++.h>
using namespace std;

#define INF 1e8+7

int dist[101][101];
int nxt[101][101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fill(&dist[0][0], &dist[100][101], INF);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == INF) {
                cout << "0\n";
                continue;
            }

            vector<int> route;
            int next = i;
            while (next != j) {
                route.push_back(next);
                next = nxt[next][j];
            }
            route.push_back(j);

            cout << route.size() << ' ';
            for (int& city : route) {
                cout << city << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
