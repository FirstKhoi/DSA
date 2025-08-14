#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/546/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, w;
    cin >> k >> n >> w;
    int ans = 0;
    for(int i = 1; i <= w; i++) {
        ans += k * i;
    }
    int borrow = max(0,ans - n);
    cout << borrow << endl;
    return 0;
}