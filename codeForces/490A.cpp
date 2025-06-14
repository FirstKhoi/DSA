#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/490/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ones, twos, threes;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 1) ones.push_back(i + 1);
        else if(a[i] == 2) twos.push_back(i + 1);
        else if(a[i] == 3) threes.push_back(i + 1);
    }
    int teams = min({ones.size(), twos.size(), threes.size()});
    cout << teams << '\n';
    for(int i = 0; i < teams; ++i) {
        cout << ones[i] << " " << twos[i] << " " << threes[i] << '\n';
    }
    return 0;
}