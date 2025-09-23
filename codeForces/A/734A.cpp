#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/734/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, a = 0, d = 0;
    cin >> n;
    string s;
    cin >> s;
    for(char c : s) {
        a += (c == 'A');
        d += (c == 'D');
    }
    if(a > d) cout << "Anton\n";
    else if(d > a) cout << "Danik\n";
    else cout << "Friendship\n";
    return 0;
}