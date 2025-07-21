#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/617/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x; cin >> x;
    int steps = x / 5;
    if (x % 5 != 0) steps++;
    cout << steps << '\n';
    return 0;
}