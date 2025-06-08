#include<iostream>
using namespace std;
#define ll long long

void displayNumber(ll x, ll y, ll z){
    cout << "Output: " << y << ", " << x << ", " << z << endl;
    cout << "Sum = " << (x + y + z) << endl;
    cout << "END!" << endl;
}

int solve(int x, int y, int z){
    cout << "28tech.com.vn" << endl;
    cout << 2 * x << " " << 3 * y << " " << 4 * z << " " << endl;
    return x * y * z;
}

int sumOfDigits(ll n){
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void inputAndProcess() {
    int N;
    cin >> N;

    ll number;
    for (int i = 0; i < N; i++) {
        cin >> number;
        cout << "Sum of digits: " << sumOfDigits(number) << endl;
    }
}

bool lastDigitOfSumIs8(long long n){
    cout << "Enter the number: "; cin >> n;
    int sum = 0 ;
    while(n){
        sum += n % 10;
        n /= 10; 
    }
    if(sum % 10 == 8 ){
        return true;
    }
    else 
    return false;
}

bool so_dep(int n){
    int c = 0, l = 0;
    while (n != 0){
        if( n % 2 == 0 ){
            c++;
        }
        else 
            l++;
        n /= 10;
    }
    return c == l;
}

void solve(int &x){
    x *= 28;
}

void drawSquare(int r,int c){
  cout << "Enter the rows: "; cin >> r;
  cout << "Enter the columns: "; cin >> c;
  for(int i = 1; i <= r ; i++){
    for(int j = 1 ; j <= c; j++){
        cout << "*" << " ";
    }
    cout << endl;
  }  
}

void drawTriangle(int l){
    cout << "Enter the length: "; cin >> l;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void drawSquareWithEmptyCenter(int r, int c){
    cout << "Enter the rows: "; cin >> r;
    cout << "Enter the columns: "; cin >> c;
    for(int i = 1; i <= r ; i++){
        for(int j = 1 ; j <= c; j++){
            if( i == 1 || i == r || j == 1 || j == c){
                cout << "*";
            }
            else
                cout <<" ";
        }
        cout << endl;
    }
}

bool findNumber6(int n){
    int original_n = n; 
    while(n > 0){
        if(n % 10 == 6){ 
        return true;
    }
        n /= 10; 
}
    return false;
}

bool tongcacchusolachan(int n){
    int sum = 0;
    while( n > 0){
        sum += n%10;
        n /=10;
    }
    if(sum % 2 == 0){
    return true; 
    }
    return false; 
}

bool evenMoreThanOdd(int n){
    int evenCount = 0, oddCount = 0;
    while( n > 0) {
        int digit = n%10;
        if(digit % 2 == 0)
            evenCount++;
        else
            oddCount++;
        n /= 10;
    }
    return evenCount > oddCount;
}



int main(){
    /*ll a, b, c, n;
    cin >> a >> b >> c;
    displayNumber(a, b, c);
    cout << solve(a, b, c) << endl;

    ll d;
    cin >> d;
    cout << sumOfDigits(d) << endl;

    cout << "Enter the number: ";
    cin >> n;
    if(lastDigitOfSumIs8(n)){
        cout << "28tech!" << endl;
    }
    else
    {
        cout << "29tech" << endl;
    }

    int Beauty_number;
    cout << "Enter so_dep: "; cin >> Beauty_number;
    for(int i= 1 ; i <= Beauty_number; i++){
        if(so_dep(i)){
            cout << i << " ";
        }   
    }
    cout << endl;

    int m;
    cout << "Enter m: "; cin >> m;
    solve(m);
    cout << m << endl;*/
    /*int r, c, l;
    drawSquare(r,c);
    drawTriangle(l);
    drawSquareWithEmptyCenter(r,c);*/
    int a,b,n;
    cout << "Enter string number with begin a num and end at num b: "; cin >> a >> b;
    for(int i = a; i <= b ; i++){
        if(findNumber6(i) && tongcacchusolachan(i) && evenMoreThanOdd(i)){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0 ;
}
