#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}


void bai1(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(isPalindrome(n)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}

bool isPrime(int n){
    if( n < 2 ) return false;
    for(int i =2 ; i <= sqrt(n); i++){
        if( n % i == 0){
            return false;
        }
    }
    return true;
}

bool isChinhPhuong(int n){
    long long can = sqrt(n);
    return can * can == n || (can + 1) * (can + 1) == n;
}

void bai2(int n){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n ; i++){
            if(isChinhPhuong(n)){
                cout << "YES" << endl;
            }
                else  cout << "NO" << endl;
        }   
    }
}


void bai3(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >>b;
        for(int i = a; i <= b; i++){
            if(isChinhPhuong(i)){
               cout << i << " ";
            }
        }
        cout << endl;
    }
}

void bai4(){
    int t ; cin >> t;
    while(t--){
        int count = 0;
        int a, b; cin >> a >> b;
        for(int i = a ; i <= b; i++){
            if(isChinhPhuong(i)){
                count++;
            }
        }
        cout << count << endl;
    }
}

void bai5(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; int sum = 0; 
        for(int i = 1 ; i <= n ; i++){
            if( n % i == 0){
                sum += i;
            }
        }
        cout << sum << endl;
    }
}

void bai6(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; int count = 0; 
        for(int i = 1 ; i <= n ; i++){
            if( n % i == 0){
                count++;
            }
        }
        cout << count << endl;
    }
}

void bai7(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(isChinhPhuong(n)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}

bool isPerfectNum(int n){
    long long sum = 1;
    if( n < 2 ) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            sum += i;
            if ( i != n / i) sum += n / i;
        }
    } 
    return sum == n;
}

void bai8(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(isPerfectNum(n)){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}

long long SumDigit(long long n){
    long long sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
}

void bai9(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        cout << SumDigit(n) << endl;
    }
}


void bai11(){
    int n; cin >> n;
    long long f[105];
    f[0] = 0;
    f[1] = 1;
    cout << f[0] << " " << f[1] << " "; 
    for(int i = 2 ; i < n; i++){
        f[i] = f[i - 1] + f[ i - 2];
        cout << f[i] << " ";
    }
    cout << endl;
}

bool isFibonacci(long long n) {
    return isChinhPhuong(5 * n * n + 4) || isChinhPhuong(5 * n * n - 4);
}

void bai12(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;

    if(isFibonacci(n)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
    }
}

long long isSumDigitIsFibo(int n){
    long long sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return isFibonacci(sum);
}

void bai13(int a, int b){
    for(int i = a ; i <= b ; i++){
        if(isPrime(i) && isSumDigitIsFibo(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

int countDistinctPrimeFactors(int n){
    int count = 0;
    
    if (n % 2 == 0) {
        count++;
        while (n % 2 == 0) n /= 2;
    }
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) n /= i;
        }
    }
    
    if (n > 1) count++;

    return count;
}

void bai14(int a, int b){
    for(int i = a; i <= b ; i++){
        if(isPalindrome(i) && countDistinctPrimeFactors(i) >= 3){
            cout << i << " ";
        }
    }
    cout << endl;
}

void bai15(int n){
    int countChan = 0; int countLe =0 ;
    while(n > 0){
        int digit = n % 10;
        if(digit % 2 == 0) countChan++;
        else countLe++;
        n /= 10;
    }
    cout << countChan << " " << countLe << endl;
}

long long factorial(int n){
    long long result = 1;
    for(int i = 2 ; i <= n; i++){
        result *= i;
    }
    return result;
}

bool isStrong(int n){
    long long sum = 0;
    int original = n;
    while(n > 0){
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }
    return sum == original;
}

void bai16(int a, int b){
    for(int i = a ; i <= b; i++){
        if(isStrong(i))
            cout << i << " ";
    }
    cout << endl;
}


void bai17(int n){
    while(n > 0){
        int digit = n % 10;
        if(digit != 6 && digit != 0 && digit != 8){
            cout << 0 << endl;
            return;
        }
        n /= 10;
    }
    cout << 1 << endl;
}

bool digitHasSix(int n){
    while(n > 0){
        int digit = n % 10;
        if(digit == 6){
            return true;
        }
        n /= 10;
    }
    return false;
}

void bai18(int a, int b){
    for(int i = a ; i <= b ; i++){
        if(isPalindrome(i) && SumDigit(i) % 10 == 8 && digitHasSix(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

void bai19(int n){
    long long res = 1;
    for(int i = 1 ; i <= n; ++i){
        res *= i;
    }
    cout << res << endl;
}

int countDigit(int n){
    int count =0 ;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

bool isArmStrong(int n){
    int original = n;
    int sum = 0;
    int count = countDigit(n);
    while(n > 0){
        int digit = n % 10;
        sum += pow(digit, count);
        n /= 10;
    }
    return sum == original;
}

void bai20(int n){
    if(isArmStrong(n)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}

bool digitNoCotains9(int n){
    while(n > 0){
        int digit = n % 10;
        if(digit != 9) return 1;
        n /= 10;
    }
    return 0;
}

void bai21(int n){
    for(int i = 2; i <= n ;i++){
        if(isPalindrome(i) && digitNoCotains9(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

void bai22(int n){
    int maxLastDigit = -1;
    for(int i = 1 ; i < n ; i++){
        if(isPrime(i)){
            int lastDigit = n % 10;
            if(lastDigit > maxLastDigit){
                maxLastDigit = lastDigit;
            }
        }
    }
    int count = 0;
    for(int i = 2; i < n; ++i){
        if(isPrime(i) && i % 10 == maxLastDigit){
            cout << i << " ";
            count ++;
        }
    }
}

long long gcd(long long a, long b){
    while( b != 0){
        long long temp =  a % b;
        a = b;
        b = temp;
    }
    return a;
}

void bai23(int a, int b){
    if(gcd(a,b) == 1) cout << 1 << endl;
    else cout << 0 << endl;
}

long long bai24(long long n){
    ll res = n;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            while(n % i ==0){
                n /= i;
            }
            res -= res / i;
        }
    }
    if(n > 1){
        res -= res / n;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //bai1();
    //int n;
    //bai2(n);
    //bai3();
    //bai4();
    //bai5();
    //bai6();
    //bai7();
    //bai8();
    //bai9();
    //bai11();
    //bai12();
    //bai13(2,50);
    //bai14(1,1000);
    //int n; cin >> n;
    //bai15(n);
    //bai16(1, 1000);
    //bai17(16808);
    //int a,b;    cin >> a >> b;
    //bai18(a,b);
    //bai19(10);
    //int n ; cin >> n;
    //bai20(n);
    //bai21(100);
    //bai23(8,128);
    int n; cin >> n;
    cout << bai24(n) << endl;
    return 0;
}