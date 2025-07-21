#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/41/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    string t; cin >> t;
    bool isReverse = true;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] != t[t.length() - 1 - i]) {
            isReverse = false;
            break;
        }
    }
    if(isReverse)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}