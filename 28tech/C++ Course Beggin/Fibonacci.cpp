#include<iostream>
using namespace std;

int main(){
    long long f[1000005];
    f[1] = 2;
    f[2] = 8;
    int mod = 1e7;
    for(int i = 3 ; i <= 1000000; i++){
        f[i] = 2 * f[i -1] + 8 * f[i - 2];
        f[i] %= mod;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}