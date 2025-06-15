#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/344/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int groups = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1]) groups++;
    }
    cout << groups << '\n';
    return 0;
}