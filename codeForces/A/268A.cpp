#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/268/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> teams(n);
    for(int i = 0; i < n; ++i) {
        cin >> teams[i].first >> teams[i].second;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j && teams[i].first == teams[j].second) {
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}