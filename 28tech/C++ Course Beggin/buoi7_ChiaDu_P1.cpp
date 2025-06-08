#include<bits/stdc++.h>
using namespace std;

void tongchiadu(int n){
    cout << "Enter n: "; cin >> n;
    int mod = 1000000007;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++){
        long long x; cin >> x;
        sum += x % mod;
        sum %= mod; //cộng tới đâu chia dư tới đó ( rất qtrong trong thuật toán lấy đồng dư )
    }
    cout << sum % mod << endl;
}

void tichchiadu(int n){
    cout <<"Enter n: "; cin >> n;
    long long mod = 10000000007;
    long long tich = 1;
    for(int i= 1 ;i <= n ; i++){
        long long x; cin >> x;
            tich *= x % mod;
            tich %= mod;
    }
    cout << tich << endl;
}

void luythuachiadu(int a, int b){
    cout << " Enter a and b: "; cin >> a >> b;
    long long mod = 1000000007;
    long long luythua = 1;
    for(int i = a; i <= b ; i++){
        luythua *= a % mod;
        luythua %= mod;
    }
    cout << luythua << endl;
}

void chusocuoicung(int k, int n, int m){
    cout << "Enter n,m: "; cin >> n >> m;
    cout << "Enter k: "; cin >> k;
    long long mod = pow(10,k);
    long long tich = 1;
    for(int i = 1; i <= m ; i++){
        tich *= n % mod;
        tich %= mod;
    }
    cout << tich << endl;
}

void giaitthua(int n){
    cout << "Enter n: " ; cin >> n;
    long long mod = 1000000007;
    long long giaithua = 1;
    for(int i = 1 ;i <= n ; i++){
        giaithua *= i % mod;
        giaithua %= mod;
        cout << giaithua << endl;
    }

}

int main(){
    int n;
    giaitthua(n);
    return 0;
}