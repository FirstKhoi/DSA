#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/514/problem/A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        int digit = n[i] - '0';
        int inverted = 9 - digit;
        if (i == 0 && digit == 9) continue;
        if (inverted < digit) n[i] = inverted + '0';
    }
    cout << n << '\n';
    return 0;
}