#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/255/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int chest = 0, biceps = 0, back = 0;
    for(int i = 0; i < n; i++) {
        if(i % 3 == 0) chest += a[i];
        else if(i % 3 == 1) biceps += a[i];
        else back += a[i];
    }

    if(chest >= biceps && chest >= back)
        cout << "chest\n";
    else if(biceps >= chest && biceps >= back)
        cout << "biceps\n";
    else
        cout << "back\n";
    return 0;
}