#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/799/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    // Time needed with one oven
    int time_one_oven = ((n + k - 1) / k) * t;
    // Simulate with two ovens
    int baked = 0, time = 0;
    while (true) {
        if (time >= d) baked += k;
        baked += k;
        time += t;
        if (baked >= n) break;
    }
    if (time < time_one_oven) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}