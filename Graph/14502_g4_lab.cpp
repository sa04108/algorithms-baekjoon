// BOJ GOLD 4
// https://www.acmicpc.net/problem/14502

#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
bool meetVirus = false;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool visit[9][9];
bool wall[9][9];
int lab[9][9];

void dfs(int y, int x) {
    visit[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (lab[ny][nx] == 2) {
            meetVirus = true;
        }
        if (!visit[ny][nx] && !wall[ny][nx] && lab[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    int ans = 0;
    for (int a = 0; a < n * m; a++) {
        if (lab[a / m][a % m]) continue;
        for (int b = a + 1; b < n * m; b++) {
            if (lab[b / m][b % m]) continue;
            for (int c = b + 1; c < n * m; c++) {
                if (lab[c / m][c % m]) continue;

                wall[a / m][a % m] = true;
                wall[b / m][b % m] = true;
                wall[c / m][c % m] = true;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (!visit[i][j] && !wall[i][j] && lab[i][j] == 0) {
                            int tmp = cnt;
                            dfs(i, j);
                            if (meetVirus) cnt = tmp;
                            meetVirus = false;
                        }
                    }
                }
                ans = max(ans, cnt);

                cnt = 0;
                wall[a / m][a % m] = false;
                wall[b / m][b % m] = false;
                wall[c / m][c % m] = false;
                fill(&visit[0][0], &visit[8][9], 0);
            }
        }
    }

    cout << ans;

    return 0;
}