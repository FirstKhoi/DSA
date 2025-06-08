#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//in ra max, min
void bai1(int n, int a[]){
    int max_val = INT_MIN, min_val = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] > max_val) max_val = a[i];
        if(a[i] < min_val) min_val = a[i];
    }
    cout << max_val << " " << min_val << endl;
}
//đếm chẵn lẻ
void bai2(int n, int a[]){
    int countChan = 0, countLe = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            countChan++;
        }
        else countLe++;
    }
    cout << countChan << " " << countLe << endl;
}
//liệt kê số ngto
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void bai3(int n, int a[]){
    for(int i = 0; i < n; i++){
        if(isPrime(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

//Tìm và in ra chỉ số của số nhỏ nhất (lớn nhất) trong mảng, nếu có nhiều số có cùng giá
//trị nhỏ nhất thì in ra chỉ số đầu tiên ( cuối cùng).
void bai4(int n, int a[]){
    int max_val = INT_MIN, min_val = INT_MAX;
    int max_pos = 0, min_pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < min_val){
            min_val = a[i];
            min_pos = i;
        }
        else if(a[i] == min_val) min_pos = i;
    }
    cout << min_pos << endl;
}
//Tìm và in ra số lớn nhất và lớn thứ 2 trong mảng. Các bạn làm thêm với số nhỏ nhất và
//nhỏ thứ 2.
void bai5(int n, int a[]){
    int max1_val = INT_MIN, max2_val = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i] > max1_val){
            max2_val = max1_val;
            max1_val = a[i];
        }  
        else if(a[i] > max2_val && a[i] < max1_val){
            max2_val = a[i];
        }
    }
    cout <<"Max1: " <<  max1_val << " " << ", Max2: " << max2_val << endl;
}

/*Tìm và in ra số lớn nhất và lớn thứ 2 trong mảng, 2 số này là 2 số có giá trị khác nhau .
Nếu không có số lớn thứ 2 in ra -1 cho số thứ 2. Các bạn làm thêm với số nhỏ nhất và nhỏ
thứ 2.*/
void bai6(int n, int a[]){
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < n; i++){
        //find max
        if(a[i] > max1){
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2 && a[i] < max1){
            max2 = a[i];
        }
        //find min
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i] < min2 && a[i] > min1){
            min2 = a[i];
        }
    }
    if(max2 == INT_MIN) cout << -1 << endl;
    else cout << "Max1: " << max1 << ", Max2: " << max2 << endl;
    if(min2 == INT_MAX) cout << -1 << endl;
    else cout << "Min1: " << min1 << ", Min2: " << min2 << endl;
}

//đếm và liệt kê các số toàn chữ số lẻ
bool isEvenDigit(int n){
    while(n > 0){
        int digit = n % 10;
        if(digit % 2 == 0){
            return false;
        }
        n /= 10;
    }
    return true;
}
void bai7(int n, int a[]){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isEvenDigit(a[i])){
            count++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < n; i++){
        if(isEvenDigit(a[i])){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

/*Cho mảng các số nguyên khác nhau đôi một. Liệt kê các phần tử trong mảng có ít nhất
2 phần tử khác lớn hơn nó.*/
void bai8(int n, int a[]){
    for (int i = 0; i < n; ++i) {
        int countLarger = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && a[j] > a[i]) {
                countLarger++;
            }
        }
        if (countLarger >= 2) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

/*Một số được định nghĩa là số đẹp nếu nó chứa cả chữ số 1 và chữ số 9. In ra các số đẹp
trong mảng. Nếu mảng không tồn tại số đẹp thì in ra -1. */
bool isDigitContains1And9(int n){
    bool hasOne = false, hasNine = false;
    while(n > 0){
        int digit = n % 10;
        if(digit == 1) hasOne = true;
        if(digit == 9) hasNine = true;
        n /= 10;
    }
    return hasOne && hasNine;
}

void bai9(int n, int a[]){
    bool found = false;
    for(int i = 0; i < n; i++){
        if(isDigitContains1And9(a[i])){
            cout << a[i] << " ";
            found = true;
        }
    }
    cout << endl;
    if(!found) cout << -1 << endl;
}

/*Cho mảng một chiều các số nguyên, liệt kê các phần tử có ít nhất một phần
tử liền kề trái dấu với nó.*/
void bai10(int n, int a[]){
    for (int i = 0; i < n; ++i) {
        if ((i > 0 && a[i] * a[i - 1] < 0) ||
            (i < n - 1 && a[i] * a[i + 1] < 0)) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

/*Kiểm tra xem mảng có đối xứng hay không, nếu có in YES, ngược lại in NO.
Input 
7
1 2 3 4 3 2 1 
Output
YES*/
void bai11(int n, int a[]){
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - i - 1]) { // Directly compare elements from start and end
        cout << "NO" << endl;
            return; // Exit the function early if asymmetry is found
    }
}
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; int a[100000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    /*bai1(n, a); 
    bai2(n, a);
    bai3(n, a);
    bai4(n ,a);
    bai5(n, a);
    bai6(n, a);*/
    //bai7(n, a);
    //bai8(n, a);
    //bai9(n, a);
    //bai10(n, a);
    bai11(n, a);
    return 0;
}