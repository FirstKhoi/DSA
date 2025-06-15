#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/767/A

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int next = n;
    vector<bool> fallen(n + 1, false);
    for (int i = 0; i < n; ++i) {
        fallen[a[i]] = true;
        if (a[i] == next) {
            while (next > 0 && fallen[next]) {
                cout << next << " ";
                --next;
            }
            cout << "\n";
        } else {
            cout << "\n";
        }
    }
    return 0;
}