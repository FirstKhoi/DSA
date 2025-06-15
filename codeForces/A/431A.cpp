#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/431/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> a(4);
    for(int i = 0; i < 4; ++i){
        cin >> a[i];
    }
    string s;
    cin >> s;
    int sum = 0;
    for(char c : s){
        sum += a[c - '1'];
    }
    cout << sum << '\n';
    return 0;
}