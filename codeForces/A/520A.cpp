#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/520/problem/A

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    set<char> letters;
    for (char c : s) {
        letters.insert(tolower(c));
    }
    if (letters.size() == 26) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}