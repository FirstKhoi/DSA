#include<iostream>
using namespace std;
//http://codeforces.com/contest/47/problem/A

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int T = 0, k = 1;
    while (T < n) {
        T += k;
        k++;
    }
    if (T == n) cout << "YES";
    else cout << "NO";
    return 0;
}