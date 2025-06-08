#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/59/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    int upper = 0, lower = 0;
    for(char c : s) {
        if(isupper(c)) upper++;
        else lower++;
    }
    if(upper > lower) {
        for(char &c : s) c = toupper(c);
    } else {
        for(char &c : s) c = tolower(c);
    }
    cout << s << endl;
    return 0;
}