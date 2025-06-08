#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/791/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b; cin >> a >> b;
    int ans = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}