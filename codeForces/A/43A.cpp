#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/43/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> bis(n);
    map<string,int> fre;
    for(auto &x : bis) cin >> x;
    for(auto &s : bis) {
        fre[s]++;
    }
    int maxd = -1;
    string win;
    for(auto &pair: fre) {
    if(pair.second > maxd) {
        maxd = pair.second;
        win = pair.first;
    }
    }
    cout << win << endl;
    return 0;
}