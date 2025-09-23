#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/265/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;

    int pos = 0;
    for (char c : t) {
        if (c == s[pos]) pos++;
        if (pos == s.size()) break;
    }
    cout << pos + 1 << '\n';

    return 0;
}