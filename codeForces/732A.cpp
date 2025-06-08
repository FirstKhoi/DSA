#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/732/problem/A

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int k, r;
    cin >> k >> r;
    for (int i = 1; ; ++i) {
        int total = k * i;
        if (total % 10 == 0 || total % 10 == r) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}