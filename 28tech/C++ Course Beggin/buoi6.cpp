#include <bits/stdc++.h>
using namespace std;

int demuoc(int n){
    int count = 0;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0)
        count++;
        if( i != n /i){
            count = n / i;
        }
    }
    return count;
}

int tonguoc(int n){
    int sum = 0 ; 
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

void listuoc(int n){
    cout << "Cac uoc so cua " << n << " la: " << endl;
    for(int i = 1; i <= sqrt(n); i++){
        if( n % i == 0){
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
    cout << endl;
}

bool checkPrimeNumber(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int gcd(int a,int b){
    while( b != 0 ){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

bool checksochinhphuong(int n){
    int temp = sqrt(n);
    if( temp * temp == n){
        return true;
    }
    return false;
}

void printsochinhphuong(int n, int a, int b){
    cout << "So chinh phuong trong doan tu " << a << " den " << b << " la: " << endl;
    int c1 = ceil(sqrt(a));
    int c2 = sqrt(b);
    for(int i = c1; i <= c2; i++){
       cout << 1ll * i * i << " ";
    }
    cout << endl;
}

int demsoluongsochinhphuong(int a, int b, int n){
    int dem = 0;
    int c1 = ceil(sqrt(a));
    int c2 = sqrt(b);
    for(int i = c1; i <= c2; i++){
        dem++;
    }
    return dem;
}

int reverseNumber(int num) {
    int reversedNumber = 0;
    while (num != 0) {
        int lastDigit = num % 10;
        reversedNumber = (reversedNumber * 10) + lastDigit;
        num /= 10;
    }
    return reversedNumber;
}


void printthuasonguyento(int n){
    cout << "Thua so nguyen to cua so " << n << " la: " << endl;
    for(int i = 2; i <= sqrt(n) ; i++){
        if( n % i == 0 ){
            while( n % i == 0){
                cout << i << " x ";
                n /= i;
            }
        }
    }
    if( n != 1)
        cout << n << endl;

}
    



int main(){
    int n;
    cout << "Enter the number: "; cin >> n;
 cout << "Uoc so cua " << n << " la: " << demuoc(n) << endl;
    listuoc(n);
    cout << "Tong cac uoc cua " << n << " la: " << tonguoc(n) << endl;
    if(checkPrimeNumber(n)){
        cout << n << " is a Prime Number" << endl;
    }
    else{
        cout << n << " is not a Prime Number" << endl;
    }

    if(checksochinhphuong(n)){
        cout << n << " la so chinh phuong!" << endl;
    }
    else
        cout << n << " khong phai la so chinh phuong!" << endl;

    cout <<  "Reversing " << n << " is: " << reverseNumber(n) << endl;

    int a, b;
    cout << "--Enter a and b-- " << endl; cout << "a: "; cin >> a; cout << "\nb: "; cin >> b;
    cout << "GCD is: "<< gcd(a,b) << endl;
    cout << "LCM is: " << lcm(a,b) << endl;
    printsochinhphuong(n,a,b);
    cout << "So luong so chinh phuong trong doan tu " << a << " den " << b << " la: " << demsoluongsochinhphuong(a,b,n) << " so" << endl;

    printthuasonguyento(n);

    
    return 0;
}