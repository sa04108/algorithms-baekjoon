// BOJ PLATINUM 5
// https://www.acmicpc.net/problem/1786

#include <bits/stdc++.h>
using namespace std;

vector<int> fail(const string &s) {
    vector<int> f(s.length());

    int j = 0;
    for (int i = 1; i < s.length(); i++) {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            f[i] = ++j;
    }

    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t, p;
    getline(cin, t);
    getline(cin, p);
    const vector<int> f = fail(p);
    vector<int> indices;

    int j = 0;
    for (int i = 0; i < t.length(); i++) {
        while (j > 0 && t[i] != p[j])
            j = f[j - 1];
        if (t[i] == p[j]) {
            ++j;
            if (j == p.length()) {
                indices.push_back(i - j + 2);
                j = f[j - 1]; // if not done, j remains out of range
            }
        }
    }

    cout << indices.size() << '\n';
    for (int &i : indices) {
        cout << i << ' ';
    }
}
