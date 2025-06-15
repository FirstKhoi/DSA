#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/427/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int police = 0, untreated = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == -1){
            if(police > 0) police--;
            else untreated++;
        } else {
            police += a[i];
        }
    }
    cout << untreated << '\n';
    return 0;
}