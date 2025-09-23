#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, a;
    cin >> n >> m >> a;
    long long res = ((n + a - 1) / a) * ((m + a - 1) / a);
    cout << res << endl;
    return 0;
}