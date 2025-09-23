#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3808/problems/492?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int current = 0;
    int total = 0;
    for(char c : s){
        int target = c - 'a';
        int delta = abs(current - target);
        total += min(delta, 26 - delta);
        current = target;
    }
    cout << total << endl;
    return 0;
}