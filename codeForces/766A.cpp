#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/766/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string a, b; cin >> a >> b;
    if(a == b){
        cout << "-1" << endl;
    } else {
        cout << max(a.length(), b.length()) << endl;
    }
    return 0;
}