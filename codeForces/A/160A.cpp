#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/160/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int &x : a) {
        cin >> x;
        total += x;
    }
    sort(a.rbegin(), a.rend());
    int sum = 0, cnt = 0;
    for (int x : a) {
        sum += x;
        cnt++;
        if (sum > total - sum) break;
    }
    cout << cnt << '\n';
    return 0;
}