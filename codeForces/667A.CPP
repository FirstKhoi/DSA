#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/677/667problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, h; cin >> n >> h;
    vector<int> a(n);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i =0; i < n; ++i){
        if(a[i] > h){
            res += 2;
        } else {
            res += 1;
        }
    }    
    cout << res << endl;
    return 0;
}