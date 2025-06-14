#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/770/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += char('a' + (i % k));
    }
    cout << res << '\n';

    return 0;
}