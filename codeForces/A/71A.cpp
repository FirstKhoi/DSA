#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/71/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        int len = s.length();
        if(len <= 10) {
            cout << s << endl;
        } else {
            cout << s[0] << len - 2 << s[len - 1] << endl;
        }
    }
    return 0;
}