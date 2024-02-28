// BOJ GOLD 4
// https://www.acmicpc.net/problem/2295

#include <bits/stdc++.h>

int arr[1001];
std::vector<int> two;

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);

    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }

    std::sort(two.begin(), two.end());

    int max = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            // two + arr[j] = arr[i]
            if (std::binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
                std::cout << arr[i];
                return 0;
            }
        }
    }
}
