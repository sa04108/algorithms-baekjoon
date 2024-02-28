// BOJ SILVER 1
// https://www.acmicpc.net/problem/6064

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        int m, n, x, y;
        std::cin >> m >> n >> x >> y;
        
        if (n == y) y = 0;

        int ans = -1;
        int lcm = m / std::gcd(m, n) * n;
        for (int i = x; i <= lcm; i += m) {
            if (i % n == y) {
                ans = i;
                break;
            }
        }

        std::cout << ans << '\n';
    }

	return 0;
}
