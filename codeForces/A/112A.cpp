#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//http://codeforces.com/contest/112/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    
    for (size_t i = 0; i < s1.size(); ++i) {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);
        if (c1 != c2) {
            cout << (c1 < c2 ? -1 : 1) << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}
