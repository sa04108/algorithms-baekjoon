// BOJ GOLD 5
// https://www.acmicpc.net/problem/2166

#include <bits/stdc++.h>
using namespace std;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
    return ((x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2)) / 2;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &v[i].first, &v[i].second);
    }

    double sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += ccw(v[0].first, v[i].first, v[i + 1].first, v[0].second, v[i].second, v[i + 1].second);
    }
    printf("%.1lf", abs(sum));
    return 0;
}