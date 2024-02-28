// BOJ SILVER 1
// https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>
using namespace std;

int video[65][65];
void dq(int n, int y, int x) {
    int zcnt = 0;
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (video[i][j] == 0) zcnt++;
        }
    }

    if (zcnt > 0 && zcnt < n * n) {
        int half = n >> 1;
        cout << '(';
        dq(half, y, x);
        dq(half, y, x + half);
        dq(half, y + half, x);
        dq(half, y + half, x + half);
        cout << ')';
    }
    else {
        cout << video[y][x];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            video[i][j] = s[j] - '0';
        }
    }

    dq(n, 0, 0);

    return 0;
}