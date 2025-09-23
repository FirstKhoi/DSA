#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3809/problems/1057?view=statement
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    int l = 0, r = n - 1;
    int timeA = 0, timeB = 0;
    int cntA = 0, cntB = 0;
    while (l <= r) {
        if (timeA <= timeB) {
            timeA += t[l++];
            cntA++;
        } else {
            timeB += t[r--];
            cntB++;
        }
    }
    cout << cntA << " " << cntB << endl;
    return 0;
}
