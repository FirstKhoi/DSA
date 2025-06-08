#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(int n){
    if( n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

/*Một số được coi là thuần nguyên tố nếu nó là số nguyên tố, tất cả các chữ số là
nguyên tố và tổng chữ số của nó cũng là một số nguyên tố. Bài toán đặt ra là đếm
xem trong một đoạn giữa hai số nguyên cho trước có bao nhiêu số thuần nguyên tố.
INPUT
23 199
OUTPUT
1*/
bool allDigitsPrime(int n) {
    while(n) {
        int d = n % 10;
        if(d != 2 && d != 3 && d != 5 && d != 7) return false;
        n /= 10;
    }
    return true;
}

int sumDigits(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void bai1(int a, int b){
    cin >> a >> b;
    int cnt = 0;
    for(int i = a; i <= b; i++) {
        if(isPrime(i) && allDigitsPrime(i) && isPrime(sumDigits(i))) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

/*Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các số
hoàn hảo(là số có tổng các ước
số nhỏ hơn nó bằng chính nó) (nếu không tồn tại số nào thì in ra 0)*/
void bai2(int a, int b){
    cin >> a >> b;
    bool found = false;
    for(int n = a; n <= b; n++) {
        int sum = 0;
        for(int i = 1; i <= n / 2; i++) {
            if(n % i == 0) sum += i;
        }
        if(sum == n) {
            cout << n << " ";
            found = true;
        }
    }
    if(!found) cout << 0;
    cout << endl;
}

/*Một số được gọi là số tăng giảm nếu số đó có các chữ số thỏa mãn hoặc tăng
dần, hoặc giảm dần từ trái qua phải.

Hãy đếm các số nguyên tố là số tăng giảm với số chữ số cho trước
INPUT
2
OUTPUT
20*/
void bai3(int n){
    int cnt = 0;
    for(int i = pow(10, n - 1); i < pow(10, n); i++) {
        if(isPrime(i)) {
            string s = to_string(i);
            bool isIncreasing = true;
            bool isDecreasing = true;
            for(int j = 1; j < s.size(); j++) {
                if(s[j] <= s[j - 1]) isIncreasing = false;
                if(s[j] >= s[j - 1]) isDecreasing = false;
            }
            if(isIncreasing || isDecreasing) cnt++;
        }
    }
    cout << cnt << endl;
}

/*Một số được coi là đẹp nếu nó là số nguyên tố và tổng chữ số là một số trong
dãy Fibonaci. Viết chương trình liệt kê trong một đoạn giữa hai số nguyên cho
trước có bao nhiêu số đẹp như vậy
INPUT
2 50
OUTPUT
2 3 5 11 17 23 41*/
bool fibonacci(long long m){
    long long f[1005];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2 ; i <= 92 ; i++){
        f[i] = f[i - 1 ] + f [ i - 2];
    }
    for(int i = 2 ; i <= 92 ; i++){
        if(m == f[i]){
            return true;
        }
    }
    return false;
}

void bai4(int a, int b){
    cin >> a >> b;
    bool first = true;
    for(int i = a; i <= b; i++){
        if(isPrime(i) && fibonacci(sumDigits(i))) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    if (!first) cout << endl;
}

/*Dãy số Fibonacci được định nghĩa như sau: F0 = 0, F1 = 1; Fi = Fi-1 + Fi-2.
Cho số nguyên dương n, với 2<=n<=92. Hãy viết chương trình in ra n số Fibonacci
đầu tiên.
INPUT
5
OUPUT
0 1 1 2 3*/
void bai5(int n){
    cin >> n;
    long long f[1005];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <=  92; i++){
        f[i] =  f[i-1] + f[i-2];
    }
    for(int i = 0; i < n; i++){
        cout << f[i] << " ";
    }
    cout << endl;
}

/*Viết chương trình phân tích một số nguyên thành các thừa số nguyên tố.
INPUT
28
OUTPUT

2 2 7*/
void bai6(int n){
    cin >> n;
    if(isPrime(n)){
        cout << n;
    }
    else{
        for(int i = 2; i <= sqrt(n); i++){
            while(n % i == 0){
                cout << i << " ";
                n /= i;
            }
        }
        if(n != 1) cout << n;
    }
    cout << endl;
}

/*Một số được coi là đẹp nếu nó là số thuận nghịch và có ít nhất 3 ước số
nguyên tố khác nhau. Viết chương trình in ra các số đẹp như vậy trong một đoạn
giữa hai số nguyên cho trước
INPUT
2 100
OUTPUT

4 6 8 9 10 12 14 15 16 18 20 21 22 24 25 26 27 28 30
*/
bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return original == reversed;
}

int countDistinctPrimeFactors(int n) {
    int count = 0;
    int lastFactor = 0;  
    
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            if (i != lastFactor) {  
                count++;
                lastFactor = i;
            }
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    
    return count;
}

void bai7(int a, int b) {
    cin >> a >> b;
    bool found = false;
    
    for (int i = a; i <= b; i++) {
        if (isPalindrome(i) && countDistinctPrimeFactors(i) >= 3) {
            if (found) cout << " ";
            cout << i;
            found = true;
        }
    }
    cout << endl;
}

/*Một số được coi là đẹp nếu nếu nó có tính chất thuận nghịch và tổng chữ số
chia hết cho 10. Bài toán đặt ra là cho trước số chữ số. Hãy đếm xem có bao nhiêu
số đẹp với số chữ số như vậy
INPUT
2
OUTPUT
1*/
void bai8(int n){
    cin >> n;
    int count = 0;
    for(int i = 0 ; i <= n ; i++){
        if(isPalindrome(i) && sumDigits(i) % 10 == 0){
            count ++;
        }
    }
    cout << count << endl;
}

/*Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các
số nguyên tố nằm trong khoảng đó
INPUT
10 50
OUTPUT
11 13 17 19 23 29 31 37 41 43 47*/
void bai9(int a, int b){
    cin >> a >> b;
    for(int i = 2 ; i <= b; i++){
        if(isPrime(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

/*Nhập một số nguyên dương N không quá 9 chữ số. Hãy đếm xem N có bao
nhiêu chữ số lẻ và bao nhiêu chữ số chẵn. Nếu không tồn tại số lẻ hoặc số chẵn thì
in ra kết quả là 0 cho loại số tương ứng

INPUT
12345678
OUTPUT
4 4*/
void bai10(int n){
    cin >> n;
    int countChan = 0, countLe = 0;
    while( n > 0){
        int digit = n % 10;
        if( digit % 2 == 0){
            countChan++;
        }
        else{
            countLe++;
        }
        n /= 10;
    }
    cout << countChan << " " << countLe << endl;
}

/*Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các
số Strong (là số có tổng giai thừa các chữ số bằng chính nó) nằm trong khoảng đó
(nếu không tồn tại số nào thì in ra 0)
INPUT
1 1000
OUTPUT
1 2 145*/
long long factorial(int n){
    long long giaithua = 1;
    for(long long i = 1; i <= n ; i++){
        giaithua *= i;
    }
    return giaithua;
}

bool isStrong(int n){
    int original  = n;
    long long sum = 0;
    while (n > 0){
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }
    return sum == original;
}

void bai11(int a, int b){
    cin >> a >> b;
    int count = 0;
    for(int i = a; i <= b; i++){
        if(isStrong(i)){
            if(count > 0) cout << " ";
            cout << i;
            count++;
        }
    }
    if(count == 0) cout << 0;
    cout << endl;
}

/*Một số được gọi là “lộc phát” nếu chỉ có các chữ số 0,6,8. Nhập vào một số
nguyên dương không quá 9 chữ số, hãy kiểm tra xem đó có phải số lộc phát hay
không. Nếu đúng in ra 1, sai in ra 0
INPUT
6068
OUTPUT
1*/
int bai12(int n){
    cin >> n;
    while(n > 0 && n < 1000000000){
        int digit = n % 10;
        if(n == 0 || n == 6 || n == 8){
            return 1;
        }
        n /= 10;
    }
    return 0;
}

/*Một số được coi là số đẹp nếu nó là số thuận nghịch, có chứa ít nhất một
chữ số 6, và tổng các chữ số của nó có chữ số cuối cùng là 8. Viết chương trình liệt
kê trong một đoạn giữa hai số nguyên cho trước có bao nhiêu số đẹp như vậy
INPUT
1 500
OUTPUT
161*/
bool isBeautifulNum(int n){
    if(!isPalindrome(n)) return false;

    bool hasSix = false;
    int temp = n;
    while(temp > 0){
        if( temp % 10 == 6 ){
            hasSix = true;
            break;
        }
        temp /= 10;
    }
    if(!hasSix) return false;
    return (sumDigits(n) % 10 == 8);
}

void bai13(int a, int b){
    cin >> a >> b;
    int count = 0;
    for(int i = a ; i <= b; i++){
        if(isBeautifulNum(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào một số n, thực hiện tìm tích của các
chữ số của n và in ra màn hình.
INPUT
1234
OUTPUT
24*/
void bai14(int n){
    cin >> n;
    int tich = 1;
    if( n == 0 ) tich = 0;
    else{ 
        while (n > 0){
        int ditgit = n % 10;
        tich *= ditgit;  
        n /= 10;
        }   
    }       
    cout << tich << endl;
}

/*Viết chương trình C cho phép nhập vào một số n và in ra tất cả các ước số
của n. (Mỗi ước được liệt kê cách nhau một khoảng trắng)
INPUT
12
OUTPUT
1 2 3 4 6 12*/
void bai15(int n){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0) cout << i <<" ";
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào số n và liệt kê tất cả các số nguyên
tố nhỏ hơn n. (Các số nguyên tố in ra cách nhau một khoảng trắng)
INPUT
20
OUTPUT
2 3 5 7 11 13 17 19*/
void bai16(int n){
    cin >> n;
    for(int i = 2; i < n ; i++){
        if(isPrime(i)){
            cout << i <<" ";
        }
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào n và thực hiện liệt kê các số
arstrong nhỏ hơn n. (Mỗi kết quả thỏa mãn cách nhau một khoảng trắng)
INPUT
1000
OUTPUT
1 2 3 4 5 6 7 8 9 153 370 371 407*/
bool isArmstrong(int num) {
    int original = num;
    int digits = 0, sum = 0;

    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

void bai17(int n){
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(isArmstrong(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

/*Số hoàn hảo là số có tổng các ước số (nhỏ hơn chính nó) bằng nó. Ví dụ: 6
= 1 + 2 + 3. Viết chương trình C cho phép nhập vào số n và kiểm tra xem n có phải
là số hoàn hảo hay không. Nếu đúng in ra 1, sai in ra 0.
INPUT
6
OUTPUT
1*/
int bai18(int n){
    cin >> n;
    int sum = 0;
    for(int i = 1 ; i < n ; i++){
        if( n % i == 0)
        sum += i;
    }
    if( sum == n){
        return 1;
    }
    else
        return 0;
}
/*Viết chương trình C cho phép nhập vào hai số a và b (a có thể lớn hơn b).
Thực hiện liệt kê các số hoàn hảo nằm trong khoảng a và b.
INPUT
1 1000
OUTPUT
6 28 496*/
bool checkPerfectNum(int n){
    int sum = 0;
    for(int i = 1;  i < n ; i++){
        if( n % i == 0){
            sum += i;
        }
    }
    if ( sum == n ) return true;
    else return false;
}

void bai19(int a, int b){
    cin >> a >> b;
    for(int i = a; i <= b ; i++){
        if(checkPerfectNum(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    //bai1(a, b);
    //int a, b;
    //bai2(a, b);
    //int n;
    //cin >> n;
    //bai3(n);
    //int a, b;
    //bai4(a, b);
    //int n;
    //bai5(n);
    //bai6(n);
    //int a, b;
    //bai7(a,b);
    //int n; 
    //bai8(n);      
    //int a,b;
    //bai9(a,b);
    //int n;
    //bai10(n);
    //int a, b;
    //bai11(a,b);
    /*int n;
    if(bai12(n)){
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
    return 0;*/
    //int a,b;
    //bai13(a,b);
    //int n;
    //bai16(n);
    //bai17(n);
    /*if(bai18(n)){
        cout << 1 << endl;
    }
    else 
        cout << 0 << endl;*/
    //int a, b;
    //bai19(a,b);
    return 0;
}