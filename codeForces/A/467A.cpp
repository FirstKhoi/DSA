#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/467/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n), rc(n);

    for(int i = 0; i < n; i++) {
        cin >> p[i] >> rc[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(rc[i] - p[i] >= 2) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}