#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/298/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;

    int firstR = -1, lastR = -1, firstL = -1, lastL = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            if(firstR == -1) {
                firstR = i;
            }
            lastR = i;
        }
        else if(s[i] == 'L') {
            if(firstL == -1) {
                firstL = i;
            }
            lastL = i;
        }
    }

    if(firstL == -1) {
        cout << firstR + 1 << " " << lastR + 2 << endl;
    } else if(firstR == -1) {
        cout << lastL + 1 << " " << firstL << endl;
    } else {
        cout << firstR + 1 << " " << firstL << endl;
    }

    return 0;
}