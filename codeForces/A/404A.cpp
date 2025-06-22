#include<bits/stdc++.h>
using namespace std;
// /https://codeforces.com/contest/404/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char diag_char = a[0][0];
    char other_char = a[0][1];
    if(diag_char == other_char) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j || i + j == n - 1) {
            if(a[i][j] != diag_char) {
                    cout << "NO" << endl;
                    return 0;
                }
            } else {
                if(a[i][j] != other_char) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}