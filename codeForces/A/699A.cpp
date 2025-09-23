#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/699/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string dir;
    cin >> dir;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        if (dir[i] == 'R' && dir[i + 1] == 'L') {
            int time = (x[i + 1] - x[i]) / 2;
            res = min(res, time);
        }
    }
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res;

    return 0;
}