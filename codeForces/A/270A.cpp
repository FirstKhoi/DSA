#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/270/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        int check = 180 - a;

        if(check == 0) {
            cout << "NO" << endl;
            continue;
        }

        if(360 % check == 0) {
            int n = 360 / check;
            if(n >= 3) {
                cout << "YES" << endl;    
            }
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}