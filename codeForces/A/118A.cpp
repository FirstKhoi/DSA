#include<bits/stdc++.h>
#include<cctype>
using namespace std;
//https://codeforces.com/contest/118/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string res = "";

    for(char &c : s) {
        c = tolower(c);
        if(c != 'a' && c != 'e' && c != 'y' && c != 'i' && c != 'o' && c != 'u') {
            res += '.';
            res += c;
        }
    }

    cout << res << endl;
    return 0;
}