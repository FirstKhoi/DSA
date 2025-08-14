#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b; cin >> a >> b;
    string res = "";
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            res += '1';
        } else 
            res += '0';
    }   
    cout << res << endl;
    return 0;
}