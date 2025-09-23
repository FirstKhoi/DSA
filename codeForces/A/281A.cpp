#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/281/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    string res = "";

    if (!s.empty()) {
        s[0] = toupper(s[0]);
    }
    cout << s << endl;
    return 0;
}
