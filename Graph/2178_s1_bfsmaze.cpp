// BOJ SILVER 1
// https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>

int maze[101][101];
bool visit[101][101];
int dist[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= m; j++) {
            maze[i][j] = s[j - 1] - '0';
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(1, 1));
    visit[1][1] = true;
    dist[1][1] = 1;

    while(!q.empty()) {
        std::pair<int, int> p = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (visit[ny][nx] || !maze[ny][nx]) continue;
            q.push(std::make_pair(ny, nx));
            visit[ny][nx] = true;
            dist[ny][nx] = dist[p.first][p.second] + 1;
        }
    }

    std::cout << dist[n][m];

    return 0;
}
