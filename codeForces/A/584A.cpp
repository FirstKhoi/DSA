#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/584/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    if (t == 10 && n == 1) {
        cout << -1;
    } else if (t == 10) {
        cout << '1';
        for (int i = 1; i < n; ++i) cout << '0';
    } else {
        for (int i = 0; i < n; ++i) cout << t;
    }
    cout << '\n';
    return 0;
}
