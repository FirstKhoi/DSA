#include<iostream>
#include<algorithm>
//https://codeforces.com/contest/41/problem/A
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    if(s == t) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}