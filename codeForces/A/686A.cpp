#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    ll count = 0;
    for (int i = 0; i < n; ++i) {
        char op;
        ll d;
        cin >> op >> d;
        if (op == '+') {
            x += d;
        } else {
            if (x >= d) {
                x -= d;
            } else {
                count++;
            }
        }
    }
    cout << x << " " << count << '\n';
    return 0;
}