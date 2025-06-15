#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, s;
    cin >> n >> s;
    long long res = s / n;
    if(s % n != 0)
        res++;
    cout << res << endl;
    return 0;
}