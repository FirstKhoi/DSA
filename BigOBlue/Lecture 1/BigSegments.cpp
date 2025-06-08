#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3808/problems/495?view=statement
int main() {
    int n; cin >> n;
    vector<pair<int, int>> segments(n);
    int minL = INT_MAX, maxR = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
        minL = min(minL, l);
        maxR = max(maxR, r);
    }
    for (int i = 0; i < n; ++i) {
        if (segments[i].first <= minL && segments[i].second >= maxR) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
