#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/231/problem/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        ans += (a + b + c >= 2);
    }
    cout << ans << '\n';
    return 0;
}
