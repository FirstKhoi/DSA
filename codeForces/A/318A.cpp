#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// https://codeforces.com/contest/318/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll odd_count = (n + 1) / 2;
    if(k <= odd_count) {
        cout << 2 * k - 1 << '\n';
    } else {
        cout << 2 * (k - odd_count) << '\n';
    }
    return 0;
}