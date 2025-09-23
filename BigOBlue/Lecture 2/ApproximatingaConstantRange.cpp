#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3809/problems/526?view=statement
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, res = 0;
    map<int, int> count;
    
    for (int r = 0; r < n; ++r) {
        count[a[r]]++;
        while (!count.empty() && count.rbegin()->first - count.begin()->first > 1) {
            count[a[l]]--;
            if (count[a[l]] == 0) {
                count.erase(a[l]);
            }
            l++;
        }
        
        res = max(res, r - l + 1);
    }
    cout << res << '\n';
    return 0;
}