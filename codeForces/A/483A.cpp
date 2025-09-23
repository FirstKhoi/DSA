#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/483/problem/A

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll left, right; cin >> left >> right;
    if (right - left < 2) {
        cout << -1 << endl;
    } else {
        if (left % 2 == 0) {
            cout << left << " " << left + 1 << " " << left + 2 << endl;
        } else if (left + 3 <= right) {
            cout << left + 1 << " " << left + 2 << " " << left + 3 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}