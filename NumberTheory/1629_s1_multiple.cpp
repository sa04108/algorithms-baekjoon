// BOJ SILVER 1
// https://www.acmicpc.net/problem/1629

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, c;
ll f(ll y) {
    if (y == 1) return a % c;

    ll k = f(y / 2);

    if (y % 2 == 0) return (k * k) % c;
    else return (k * k % c) * (a % c) % c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b >> c;
    cout << f(b);
    return 0;
}