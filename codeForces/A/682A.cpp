#include<bits/stdc++.h>
using namespace std;
//http://codeforces.com/contest/682/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    long long c = 0;
    for(long long i = 1; i <= n; i++) {
        c += (m + i % 5) / 5;
    }
    cout << c << endl;

    return 0;
}