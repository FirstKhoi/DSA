#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/225/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> sides(n);
    for(int i = 0; i < n; i++) {
        cin >> sides[i].first >> sides[i].second;
    }

    for(int i= 0; i < n; i++) {
        int a = sides[i].first;
        int b = sides[i].second;
        int top = x, bottom = 7 - x;
        if(a == top || a == bottom || b == top || b == bottom) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}