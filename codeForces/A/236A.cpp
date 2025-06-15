#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/236/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    set<char> distinct_chars(s.begin(), s.end());
    if (distinct_chars.size() % 2 == 0)
        cout << "CHAT WITH HER!\n";
    else
        cout << "IGNORE HIM!\n";
    return 0;
}