#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/742/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if(n == 0) {
        cout << 1 << endl;
    }
    else {
        int res[] = {8, 4, 2, 6};
        cout << res[(n - 1) % 4] << endl;
    }
    return 0;
}