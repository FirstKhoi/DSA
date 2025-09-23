#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/266/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i - 1]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}