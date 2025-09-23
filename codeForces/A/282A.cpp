#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s == "X++" || s == "++X") {
            res++;
        } else res--;
    }
    cout << res << endl;
    return 0;
}
