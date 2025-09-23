#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/9/problem/A
int _gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return _gcd(b, a % b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int y, w; cin >> y >> w;
    int maxRoll = max(y, w);
    int favorable = 6 - maxRoll + 1;
    int total = 6;
    int gcd = _gcd(favorable, total);
    cout << favorable / gcd << "/" << total / gcd << "\n";
    return 0;
}