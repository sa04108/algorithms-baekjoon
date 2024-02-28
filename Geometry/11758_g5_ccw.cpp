// BOJ GOLD 5
// https://www.acmicpc.net/problem/11758

#include <bits/stdc++.h>
using namespace std;

struct Coordinate {
    int x;
    int y;
};

int ccw(vector<Coordinate>& cv) {
    return (cv[1].x - cv[0].x) * (cv[2].y - cv[0].y) - (cv[2].x - cv[0].x) * (cv[1].y - cv[0].y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<Coordinate> v;
    int n = 3;
    while (n--) {
        Coordinate coord;
        cin >> coord.x >> coord.y;
        v.push_back(coord);
    }

    int result = ccw(v);
    if (result < 0) cout << -1;
    else cout << (result > 0);
    
    return 0;
}