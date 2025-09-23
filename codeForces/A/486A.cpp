#include <iostream>
using namespace std;
//http://codeforces.com/contest/486/problem/A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long res;
    if(n % 2 == 0) {
        res = n / 2;
    }
    else {
        res = -(n + 1) / 2;
    }
    cout << res << endl;
    return 0;
}
