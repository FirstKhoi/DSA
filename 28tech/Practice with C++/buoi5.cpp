#include<bits/stdc++.h>
using namespace std;

long long factorial(int n){
    long long giaithua = 1; 
    for(int i = 2; i <= n ; i++){
        giaithua *= i;
    }
    return giaithua;
}

bool isStrong(int n){
    int temp = n;
    int giaithua = 0;
    while(n > 0){
        int digit = n % 10;
        giaithua += factorial(digit);
        n /= 10;
    }
    return giaithua == temp;
}
/*Số Strong là số thỏa mãn có tổng giai thừa các chữ số của nó bằng chính
nó. Ví dụ: 145 = 1! + 4! + 5!
Viết chương trình C cho phép nhập vào số n và kiểm tra xem n có phải số Strong
hay không. Nếu đúng in ra 1 sai in ra 0.
INPUT
145
OUTPUT
1*/
int bai1(int n){
    cin >> n;
    if(isStrong(n)){
        return 1;
    }
    else{
        return 0;
    }
}

/*Viết chương trình C cho phép nhập vào một số n bất kỳ, tìm và in ra chữ số
đầu tiên và cuối cùng của n.
INPUT
1234
OUTPUT
1 4*/
void bai2(int n){
    cin >> n;
    int last_digit = n % 10;
    int first_digit = n;
    while (first_digit >= 10){
        first_digit /= 10;
    }
    cout << first_digit << " " << last_digit << endl;
}

/*Viết chương trình C cho phép nhập vào một số n, thực hiện tìm tổng các
chữ số của n và in ra màn hình.
INPUT
1234
OUTPUT
10*/
void bai3(int n){
    cin >> n;
    int sum = 0;
    n = abs(n);
    while ( n > 0 ){
        sum += n % 10;
        n /= 10;
    }
    cout << sum << endl;
}

/*Kiểm tra số ngto, đúng in 1, sai in 0*/
bool isPrime(int n){
    if ( n < 2 ) return 0;
    for(int i = 2 ; i <= sqrt(n); i++){
        if( n % i == 0)
        return 0;
    }
    return 1;
}

void bai4(int n){
    cin >> n;
    if(isPrime(n)){
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
}

/*Tính giai thừa*/
void bai5(int n){
    cin >> n;
    long long giaithua = 1;
    for(long long i = 1; i <= n; i++){
        giaithua *= i;
    }
    cout << giaithua << endl;
}

    /*Số hoàn hảo là số có tổng các ước số (nhỏ hơn chính nó) bằng nó. Ví dụ: 6
    = 1 + 2 + 3.
    Viết chương trình cho phép nhập vào số n và liệt kê các số hoàn hảo nhỏ hơn n.
    INPUT
    1000
    OUTPUT
    6 28 496*/
bool isPerfecttemp(int n){
    int sum = 0;
    for(int i = 1; i < n ; i++){
        if( n % i == 0)
            sum += i;
    }
    return sum == n;
}

void bai6(int n){
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        if(isPerfecttemp(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào một số nguyên n và thực hiện đổi
vị trí của chữ cái đầu tiên và chữ cái cuối cùng.
Lưu ý trong trường hợp chữ số cuối cùng là 0 thì khi đổi chỗ sẽ được loại bỏ (ví dụ
9800 -> 809)
INPUT
1234
OUTPUT
4231*/
int reversetempber(int temp) {
    int reversedtempber = 0;
    while (temp != 0) {
        int lastDigit = temp % 10;
        reversedtempber = (reversedtempber * 10) + lastDigit;
        temp /= 10;
    }
    return reversedtempber;
}

/*Viết chương trình C cho phép nhập vào một số n và kiểm tra xem n có bao
nhiêu chữ số.
INPUT
1234
OUTPUT
4*/
int bai8(int n){
    int countDigit = 0;
    while ( n > 0 ){
        int digit = n % 10;
        countDigit++;
        n /=10;
    }
    return countDigit;
}

/*Số armstrong là số A có n chữ số và thỏa mãn tổng của lũy thừa bậc n của
từng chữ số trong A bằng chính nó.
Ví dụ: 371 = 3mũ3 + 7mũ3 + 1mũ3
Viết chương trình C kiểm tra một số xem có phải là số armstrong hay không. Nếu
đúng in ra 1, sai in ra 0.
INPUT
371
OUTPUT
1*/
bool isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int countDigit = 0;
    int temp = num;

    // Đếm chữ số
    while (temp > 0) {
        countDigit++;
        temp /= 10;
    }

    temp = num;  // GÁN LẠI temp ĐỂ DÙNG LẠI!

    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, countDigit);
        temp /= 10;
    }

    return sum == original;
}

void bai9(int n){
    if(isArmstrong(n)){
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
}


/*Tam giác pascal là tam giác có công thức tính giá trị một vị trí bất kỳ như
sau
(n,k) = n!/k!(n-k)!
Trong đó: n là hàng và k là cột.
Viết chương trình C cho phép nhập vào n và in ra tam giác pascal tương ứng (lưu ý
mỗi phần tử cách nhau 1 khoảng trắng)
INPUT
5
OUTPUT
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1 */
long long combination(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void bai10(int n){
    for(int i= 0; i <= n; i++){
        for(int j = 0; j <= i ; j++){
            cout << combination(i,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào một số n và kiểm tra số đó có thuộc dãy
fionacci hay không. Nếu thỏa mãn in ra 1, ngược lại in ra 0.
INPUT
8
OUTPUT
1*/
bool checkFibonacci(long long n){
    long long f[93];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 92 ; i ++){
        f[i] = f[i-1] + f[i - 2];
    }
    for(int i = 0 ; i <= 92; i++){
        if(f[i] == n )
            return true;
    }
    return false;
}

void bai11(int n){
    if(checkFibonacci(n)){
        cout << 1 << endl;
    }
    else    cout << 0 << endl;
}

/*Viết chương trình C cho phép nhập vào n. Thực hiện liệt kê các số nguyên
tố nhỏ hơn n và thỏa mãn có tổng các chữ số chia hết cho 5. Có bao nhiêu số như vậy
INPUT
100
OUTPUT
5 19 23 37 41 73
6*/
int sumDigit(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void bai12(int n){
    int countPrimeNum = 0;
    int sum = 0;
    for(int i = 2; i < n; i++){
        if(isPrime(i) && sumDigit(i) % 5 == 0){
            cout << i << " ";
            countPrimeNum++;
        }
    }
    cout << "\n" << countPrimeNum << endl; 
}
/*Viết chương trình C cho phép nhập vào số N, thực hiện liệt kê các số thuận nghịch
lớn hơn 1 và nhỏ hơn N thỏa mãn không chứa chữ số 9. Có bao nhiêu số như vậy.
INPUT
100
OUTPUT
2 3 4 5 6 7 8 11 22 33 44 55 66 77 88
15*/
bool isPalindromeskip9(int n){
    int original = n;
    int reveresd = 0;
    int temp = n;
    while(temp > 0){
        int digit = temp % 10;
        if(digit == 9) return false;
        reveresd = reveresd * 10 + n % 10;
        temp /= 10;
    }
    return reveresd == original;
}

void bai13(int n){
    int count = 0;
    for(int i = 2; i < n ; i++){
        if(isPalindromeskip9(i)){
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << count << endl;
}

/*Viết chương trình C cho phép nhập vào n và liệt kê các số nguyên tố thỏa
mãn nhỏ hơn n và có chữ số cuối cùng lớn nhất. Có bao nhiêu số như vậy
INPUT
200
OUTPUT
2 3 5 7 11 13 17 19 23 29 37 47 59 67 79 89 101 103 107 109 113 127 137 139 149
157 167 179 199
29*/
void bai14(int n){
    int maxDigit = 0;
    for(int i = 2; i < n; i++){
        if(isPrime(i)){
            int lastDigit = i % 10;
            if(lastDigit > maxDigit){
                maxDigit = lastDigit;
            }
        }
    }

    int count = 0;
    for(int i = 2 ; i < n ; i++){
        if(isPrime(i) && ( i % 10 == maxDigit)){
            cout << i << " ";
            count++;    
        }
    }
    cout << endl;
    cout << count << endl;
}

/*Viết chương trình C cho phép nhập vào 2 số a và b. Sắp xếp a, b theo thứ tự tăng
dần tổng các chữ số.
(Nếu a và b có tổng các chữ số bằng nhau thì in ra a trước)
INPUT
99 1111
OUTPUT
1111 99*/
void bai15(int a, int b){
    if(sumDigit(a) > sumDigit(b)){
        cout << b << " " << a << endl;
    }
    else if(sumDigit(a) < sumDigit(b)){
        cout << a << " " << b << endl;
    }
    else
        cout << a << " " << b << endl;
}

/*Một số được coi là số đẹp khi nó đồng thời vừa chia hết cho một số nguyên tố và
chia hết cho bình phương của số nguyên tố đó. Viết chương trình liệt kê các số đẹp
như vậy trong đoạn giữa hai số nguyên dương cho trước.
INPUT
1 50
OUTPUT
4 8 9 12 16 18 20 24 25 27 28 32 36 40 44 45 48 49 50*/

void bai16(int a, int b){
    for(int i = a; i <= b ; i++){
        for(int p = 2; p * p <= i; p++)
        if(i % isPrime(p) == 0 && i % (p * p ) == 0 ){
            cout << i << " ";
            break;
        }
    }
    cout << endl;
}

/*Viết chương trình phân tích một số nguyên thành các thừa số nguyên tố.
INPUT
28
OUTPUT
2x2x7*/
void bai17(int n){
    for(int i = 2; i <= n ;i++){
        while(n % i == 0){
            cout << i;
            n /= i;
            if(n > 1) cout << "x";
        }
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào một số n, thực hiện đếm số lần xuất
hiện của các chữ số nguyên tố trong n và in ra màn hình. (Liệt kê theo thứ tự xuất
hiện các chữ số)
INPUT
3112345
OUTPUT
3 2
2 1
5 1*/
void bai18(int n){
    int count[10] = {0};

    while(n > 0){
        int digit = n % 10;

        if(digit == 2 || digit == 3 || digit == 5 || digit == 7){
            count[digit]++;
        }

        n /= 10;
    }

    bool printed = false;
    for(int i = 2; i <= 7; i++){
        if(count[i] > 0){
            if(printed)
                cout << " ";
            else
                printed = true;

            cout << i << " " << count[i];
        }
    }

    cout << endl;
}

/*Một số được coi là số đẹp nếu nó là số nguyên tố và ngược lại của nó cũng
là một số nguyên tố khác. Viết chương trình liệt kê các số đẹp như vậy trong một
đoạn giữa hai số nguyên dương cho trước.
INPUT
1 50
OUTPUT
13 17 31 37*/
int reversedNum(int n){
    int reversed = 0;
    while (n > 0){
        reversed = reversed * 10 + n % 10;
        n  /= 10;
    }
    return reversed;
}

void bai19(int a, int b){
    for(int i = a; i <= b;i++){
        int reversed = reversedNum(i);
        if(isPrime(i) && isPrime(reversed) && reversed != i){
            cout << i << " ";
        }
    }
    cout << endl;
}

/*Một số được coi là số đẹp khi nếu nó chia hết cho một số nguyên tố nào đó
thì cũng chia hết cho bình phương của số nguyên tố đó. Viết chương trình liệt kê
các số đẹp như vậy trong đoạn giữa hai số nguyên dương cho trước.
INPUT
1 50
OUTPUT
4 8 9 16 25 27 32 36 49*/
bool isBeautiful(int n){
    for(int i = 2; i <= n; i++){
        if(isPrime(i) && n % i == 0){
            if(n % (i * i) != 0){
                return false; // chia cho i nhưng không chia cho i^2 => không đẹp
            }
        }
    }
    return true;
}

void bai20(int a, int b){
    for(int i = 2; i <= b; i++){
        if(isBeautiful(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}


int main(){
    /*int n;
    if(bai1(n) == 1){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }*/
   //int n; cin >> n;
   //bai2(n);
   //bai3(n);
   //bai4(n);
   //bai5(n);
   //bai6(n);
   //cout << reversetempber(n) << endl;
   //cout << bai8(n) << endl;
   //bai9(n);
   //bai10(n);
   //bai11(n);
   //bai12(n);
   //bai13(n);
   //bai14(n);
   int a, b;
   cin >> a >> b;
   //bai16(a,b);
   //bai17(n);
   //bai18(n);
   //bai19(a, b);
   bai20(a,b);
   return 0;
}





