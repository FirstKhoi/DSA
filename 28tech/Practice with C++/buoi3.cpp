#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

//s = 1+2+3+...+n+n+1...
int suminterger(int n){
    int sum = 0 ;
    for(int i = 0 ; i <= n; i++){
        sum += i;
    }    
    return sum;
}

//s = 1^2+2^2+...+n^2
int tongbinhphuongcacso(int n){
    int sum = 0 ;
    for(int i= 0 ; i <= n ; i++){
        sum += pow(i,2);    
    }
    return sum;
}

//tổng số nguyên dương không vượt quá n và chia hết cho 3
int sumchiahetcho3(int n){
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        if( n % 3 == 0 ){
            sum += i;
        }
    }
    return sum;
}

// s = 1 + 1/2 + 1/3 + ... +  1/n
float sumphanso(float n){
    float sum = 0;
    for(float i= 1 ; i <= n ;i++){
        sum += 1/i;
    }
    return sum;
} 

//S=1/2 +1/4 +1/6+1/8+.......+1/(2n).
float sumphanso2(float n){
    float sum = 0 ;
    for(float i = 1 ; i <= n ; i++){
        sum += 1/(2*i);
    }
    return sum;
}

//S=-1 + 2 - 3 + 4 -5 +.....+ (-1)^n*n
int bai6(int n){
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        if (i % 2 == 0)
            sum += i;
        else
            sum -= i;
    }
    return sum;
}

//S=2+4+6+8+......+2*n
int bai7(int n){
    int sum = 0;
    for(int i = 1 ; i <= n; ++i){
        sum += 2 * i;
    }
    return sum;
}

//S=1+3+5+7+.....+2*n-1
int bai8(int n){
    int sum = 1 ;
    for(int i = 1; i <= n; i++){
        sum += 2 * i - 1 ;
    }
    return sum;
}

//S=1^3+2^3+3^3+4^3+......+n^3.
int bai9(int n){
    int sum = 0; 
    for(int i = 1; i <= n ; i++){
        sum += pow(i,3);
    }
    return sum;
}

// /Nhap n khong am
//n!=1.2.3......n!
int bai10(int n){
    do{
        cout << "Enter n: "; cin >> n;
        if( n < 0){
            cout << "Enter n > 0!" << endl;
        }
    }while( n < 0 );
    int giaithua = 1;
    for(int i = 1 ; i <= n; i++){
        giaithua *= i;
    }
    return giaithua;
}

//Nhập x,y nguyên không âm, tính x^y và in kết quả ra màn hình.
int bai11(int x,int y){
    do{
        cout << "Enter x and y in 1 line: "; cin >> x >> y;
        if( x < 0 || y < 0){
            cout << "Both of them should be greater than 0!" << endl;
        }
    }while(x < 0 || y < 0);
    return pow(x,y);
}

//Nhập vào n (0<=n<=10^18), đếm số lượng chữ số của n và in ra kết quả.
int bai12(long long num){
    if(num == 0) return 1;

    int count = 0;
    while(num > 0){
        num /= 10;
        count++;
    }
    return count;
}

//Nhập vào n (0<=n<=10^18), tính tổng các chữ số của n, và in ra kết quả
int bai13(long long num){
    int sum = 0;
    if(num == 0) return 1;

    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

//Nhập vào n(0<=n<=10^18), tính tổng các chữ số là số chẵn và tổng các chữ
//số là số lẻ, in ra 2 tổng chẵn lẻ trên 2 dòng.
void bai14(long long num){
    int sumChan = 0, sumLe = 0;
    if(num == 0) {
        cout << "Sum of even digits: " << sumChan << endl;
        cout << "Sum of odd digits: " << sumLe << endl;
        return;
    }

    while( num > 0){
        int digit = num % 10;
        if(digit % 2 == 0){
            sumChan += digit;
        } else {
            sumLe += digit;
        }
        num /= 10;
    }

    cout << "Sum of even digits: " << sumChan << endl;
    cout << "Sum of odd digits: " << sumLe << endl;
}


//Nhập vào n (0<=n<=10^18), in ra số lượng chữ số chẵn, lẻ của n.
void bai15(long long n){
    int countChan = 0, countLe = 0;
    if(n == 0) {
        cout << "Even digits: 1" << endl << "Odd digits: 0" << endl;
    }

    while(n > 0){
        int digit = n % 10;
        if(digit % 2 == 0){
            countChan++;
        } else {
            countLe++;
        }
        n /= 10;
    }

    cout << "Even digits: " << countChan << endl << "Odd digits: " << countLe << endl;
}

//Nhập vào n nguyên (0<=n<=10^18). Đếm số lượng chữ số của n là số nguyên tố.
bool checkPrime(int n){
    for(int i = 2 ; i <= sqrt(n); i++){
        return true;
    }
    return n > 1;
}

int bai16(long long n){
    int count = 0;
    while(n > 0){
        int digit = n % 10;
        if(checkPrime(digit)){
            count++;
        }
        n /= 10;
    }
    return count;
}


//Số đẹp được định nghĩa là số mà trong đó số lượng chữ số chẵn và lẻ của n
//là bằng nhau. Nhập vào một số nguyên dương n (0<=n<=10^18). Nếu số nhập vào
//là số đẹp, thì in ra “YES”, trường hợp ngược lại in ra “NO”.
void bai17(long long n){
    int countChan = 0;
    int countLe = 0;
    if(n == 0) {
        cout << "YES" << endl;
        return;
    }

    while( n > 0 ){
        int digit = n % 10;
        if(digit % 2 == 0){
            countChan++;
        } else {
            countLe++;
        }
        n /= 10;
    }
    if(countChan == countLe)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

//Cho số nguyên dương n biểu diễn n dưới dạng tổng của các số nguyên tố
//sao cho số lượng số hạng trong tổng là lớn nhất.
void bai18(int n){
    if (n % 2 == 0) {
        int count = n / 2;
        cout << count << endl;
        for (int i = 0; i < count; ++i) {
            cout << 2 << " ";
        }
        cout << endl;
    } else {
        int count = n / 2;
        cout << count << endl;
        cout << 3 << " ";
        for (int i = 0; i < count - 1; ++i) {
            cout << 2 << " ";
        }
        cout << endl;
    }
}          

/*Olesya thích các số gồm n chữ số và Rodion chỉ thích các số chia hết cho t.
--Tìm một số số thỏa mãn cả hai.
--Nhiệm vụ của bạn là: cho n và t in một số nguyên lớn hơn 0 bao gồm n chữ số chia
hết cho t. 
Nếu số đó không tồn tại, in - 1.
Input
Dòng đơn chứa hai số, n và t (1 <= n<= 100, 2 ≤ t <=10) - độ dài của số và số nên
chia hết cho.Output
In một số dương như vậy mà không có số 0 đứng đầu, - câu trả lời cho vấn đề, hoặc
- 1, nếu số đó không tồn tại. Nếu có nhiều câu trả lời có thể, bạn được phép in bất
kỳ câu trả lời nào.*/

int bai19(int n,int t){
    cout << "Enter n and t: " ; cin >> n >> t;
    if (t == 10) {
        if (n == 1) {
            cout << -1 << endl;
        } else {
            cout << "1";
            for (int i = 1; i < n; ++i)
                cout << "0";
            cout << endl;
        }
    } else {
        cout << t;
        for (int i = 1; i < n; ++i)
            cout << "0";
        cout << endl;
    }

    return 0;
}

/*Input
Dòng đầu tiên chứa số nguyên n n (1 ≤ n <=100) - số vòng chơi.
Các dòng n tiếp theo chứa mô tả vòng thứ i trong số chúng chứa cặp số nguyên mi
và ci (1 ≤ mi, ci ≤ 6) - các giá trị trên mặt xúc xắc sau khi Mishka và Chris 'lần lượt
ném vào vòng thứ i.
Output
Nếu Mishka là người chiến thắng trong trò chơi, hãy in "Mishka" (không có dấu
ngoặc kép) trong dòng duy nhất.
Nếu Chris là người chiến thắng trong trò chơi, hãy in "Chris" (không có dấu ngoặc
kép) trong dòng duy nhất.
Nếu kết quả của trò chơi là hòa, hãy in "Friendship is magic! ^^" (không có dấu
ngoặc kép) trong dòng duy nhất.*/
void bai20(int n, int M,int C){
    int countM = 0 ; int countC = 0 ;
    cout << "Round: "; cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> M >> C;
        }
        if ( M > C){
            countM++;
        }
        else{
            countC++;
        }
    if(countM > countC)
        cout << "Mishka" << endl;
    else if ( countC > countM)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!";
}

/*
Input
Dòng đầu tiên của đầu vào chứa số nguyên dương n (1 <= n<= 1 000 000) - số ngày
trong một năm trên Sao Hỏa.
Output
In hai số nguyên -số ngày nghỉ tối thiểu có thể và số ngày nghỉ tối đa có thể mỗi
năm trên Sao Hỏa.*/
void bai21(int n){

    cout << "Enter number of days in Sao Hoa: "; cin >> n;

    int fullWeeks = n / 7;
    int daysLeft = n % 7;

    int minDaysOff = fullWeeks * 2;
    int maxDaysOff = minDaysOff + min(2, daysLeft);

    cout << minDaysOff << " " << maxDaysOff << endl;
        

}

/*Đếm số cách đặt 2 con mã trên bàn cờ vua cỡ k × k với k = 1, 2, 3, .. n sao cho chúng
không ăn nhau, 2 con mã này được coi là giống nhau.
Input
Số nguyên dương n duy nhất ( 1 ≤n ≤10000).
Output
Gồm n dòng, mỗi dòng là đáp án của bài toán.
Giải thích : với bàn cờ cỡ 1 x 1, không có cách nào. Với bàn cờ cỡ 2x2 có 6 cách đặt 2
con mã sao cho chúng không ăn nhau. Tương tự với các cỡ từ 3 tới 7.*/
#include <iostream>
using namespace std;


void bai22(int n) {
    cout << "n: "; cin >> n;
    for (int k = 1; k <= n; ++k) {
        
        long long total_cells = k * k;
        
        
        long long total_ways = total_cells * (total_cells - 1) / 2;

        long long attack_ways = 0;
        
        
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
               
                int possible_moves = 0;

       
                if (i - 2 >= 0 && j - 1 >= 0) possible_moves++; // (i-2, j-1)
                if (i - 2 >= 0 && j + 1 < k) possible_moves++;  // (i-2, j+1)
                if (i - 1 >= 0 && j - 2 >= 0) possible_moves++;  // (i-1, j-2)
                if (i - 1 >= 0 && j + 2 < k) possible_moves++;   // (i-1, j+2)
                if (i + 1 < k && j - 2 >= 0) possible_moves++;   // (i+1, j-2)
                if (i + 1 < k && j + 2 < k) possible_moves++;    // (i+1, j+2)
                if (i + 2 < k && j - 1 >= 0) possible_moves++;   // (i+2, j-1)
                if (i + 2 < k && j + 1 < k) possible_moves++;    // (i+2, j+1)

                attack_ways += possible_moves;
            }
        }

        attack_ways /= 2;

        
        long long safe_ways = total_ways - attack_ways;

       
        cout << safe_ways << endl;
    }
}
/*Có n quả táo và m cái hộp, tìm số cách chia n quả táo này vào m hộp sao cho hộp nào
cũng có ít nhất 1 quả táo.
Input
2 số nguyên dương n , m ( 1 ≤ m ≤ n ≤ 20).
Output
Kết quả của bài toán*/
long long tinhGiaiThua(int n){
    long long giaithua = 1;
    for(int i= 1 ; i < n ; i++){
        giaithua *=i ;
    }
    return giaithua;
}

long long bai23(int n, int m,int k ){
    cout << "Enter the num of apple: "; cin >> n;
    cout << "Enter the box: "; cin >> m;
    if( k > n ) return 0;
    return tinhGiaiThua(n) / (tinhGiaiThua(k) * tinhGiaiThua( n - k ));
}


int main(){
    int n;
    
    /*cout <<  suminterger(n) <<  endl;
    cout << tongbinhphuongcacso(n) << endl;
    cout << sumchiahetcho3(n) << endl;
    cout << bai6(n) << endl;
    cout << bai7(n) << endl;
    cout << bai8(n) << endl;
    cout << bai9(n) << endl;
    cout << bai10(n) << endl;*/
    
    //int num; 
    //cout << "Dem so luong chu so va tinh tong cac chu so: "; cin >> num;
    //if(bai12(num) == 1){
   //     cout << "1" << endl;
    //}
    //else
    //cout << "Count: " << bai12(num) << endl;
   // if(bai13(num) ==1){
    //    cout << "0" << endl;
    //}
    //else
    //cout<< "Sum = " << bai13(num) << endl;
    //bai14(num);
   //bai15(num);
    //cout << bai16(n) << endl;
    //bai17(n);
    //bai18(n);

    //float m;
    //cout << "Enter m: "; cin >> m;
    //cout << setprecision(4) << sumphanso(m) << endl;
    //out << setprecision(3) << sumphanso2(m) << endl;
    //bai19(n, t);
    //bai20(n , M, C);
    //bai21(n);
    //bai22( n);
    //int m,k;
    //cout << bai23(n,m,k) << endl;
    return 0;
}