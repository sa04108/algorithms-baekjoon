// BOJ GOLD 3
// https://www.acmicpc.net/problem/11997

#include <bits/stdc++.h>
using namespace std;

int x[1001];
int y[1001];
int mat[1001][1001];
int sum[1001][1001];
vector<int> px;
vector<int> py;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        cin >> y[i];
        px.push_back(x[i]);
        py.push_back(y[i]);
    }

    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    // 중복된 값을 제거하고 뒤에 있는 똥값 날리기
    px.erase(unique(px.begin(), px.end()), px.end());
    py.erase(unique(py.begin(), py.end()), py.end());

    // 좌표 압축 = 이분탐색으로 x[i]를 찾고 x[i] 보다 작은 값의 개수로 압축
    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(px.begin(), px.end(), x[i]) - px.begin() + 1;
        y[i] = lower_bound(py.begin(), py.end(), y[i]) - py.begin() + 1;
        mat[x[i]][y[i]]++;
    }

    // 2차원 누적합 구하기: 동적계획법 사용
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mat[i][j];
        }
    }

    // 구간을 4등분하여 차례로 구간별 소의 마리 수 구하기
    int M = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int part = sum[i][j];
            part = max(part, sum[i][n] - sum[i][j]);
            part = max(part, sum[n][j] - sum[i][j]);
            part = max(part, sum[n][n] - sum[i][n] - sum[n][j] + sum[i][j]);
            M = min(M, part);
        }
    }

    cout << M;

    return 0;
}
