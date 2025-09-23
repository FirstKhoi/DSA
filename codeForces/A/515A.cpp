#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, s;
    cin >> a >> b >> s;
    if(s < a + b || (s - a - b) % 2 != 0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}