#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/529?view=statement
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n);
    for (int &x : h) cin >> x;
    sort(h.begin(), h.end());
    int res = h[b] - h[b-1];
    cout << (res > 0 ? res : 0) << '\n';
    return 0;
}