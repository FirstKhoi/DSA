#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/228/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> a(4);
    for(int i = 0; i < 4; ++i){
        cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    cout << 4 - s.size() << endl;
}
