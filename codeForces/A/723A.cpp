#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/723/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> x(3);
    for(int i = 0; i < 3; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int min_distance = x[2] - x[0];
    cout << min_distance << endl;
    return 0;
}