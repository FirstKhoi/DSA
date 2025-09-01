#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3844/problems/814?view=statement

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int case_num = 1;
    while (true) {
        int N, Q;
        cin >> N >> Q;
        if (N == 0 && Q == 0) break;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << "CASE# " << case_num++ << ":\n";
        for (int i = 0; i < Q; i++) {
            int x;
            cin >> x;
            auto it = lower_bound(a.begin(), a.end(), x);
            if (it != a.end() && *it == x) {
                cout << x << " found at " << (it - a.begin() + 1) << '\n';
            } else {
                cout << x << " not found\n";
            }
        }
    }
    return 0;
}