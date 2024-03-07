// BOJ BRONZE 2
// https://www.acmicpc.net/problem/16916

#include <bits/stdc++.h>
using namespace std;

vector<int> fail(const string &s) {
    vector<int> f(s.length());

    int j = 0;
    for (int i = 1; i < s.length(); i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s, p;
    cin >> s >> p;
    const vector<int> f = fail(p);

    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        while (j > 0 && s[i] != p[j]) j = f[j - 1];
        if (s[i] == p[j]) {
            ++j;
            if (j == p.length()) {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
}
