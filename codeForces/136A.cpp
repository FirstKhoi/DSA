#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/136/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[a[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}