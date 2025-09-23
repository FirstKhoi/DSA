#include<bits/stdc++.h>
using namespace std;
//http://codeforces.com/contest/556/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s;
    cin >> s;

    int count1 = 0, count0 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') count1++;
        else if(s[i] == '0') count0++;
    }
    cout << abs(count1 - count0) << endl;
    return 0;
}