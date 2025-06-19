#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/469/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    set<int> levels;
    int p, x;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> x;
        levels.insert(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> x;
        levels.insert(x);
    }
    if ((int)levels.size() == n)
        cout << "I become the guy.\n";
    else
        cout << "Oh, my keyboard!\n";
    return 0;
}