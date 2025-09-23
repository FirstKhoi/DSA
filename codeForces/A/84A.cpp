#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/84/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if(n % 2 != 0) {
        cout << 0 << endl;
    } else {
        cout << n / 2 << endl;
    }
    return 0;
}