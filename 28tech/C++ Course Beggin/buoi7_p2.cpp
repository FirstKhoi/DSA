#include<iostream>
using namespace std;

void enterArray(int a[100], int &n){
    cout << "Enter number of array: " ; cin >> n;
    for(int i= 0 ; i < n; i++){
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
}

void printArray(int a[100], int n){
    cout << "PrintArrayLeftToRight: ";
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "PrintArrayRightToLeft: ";
    for(int i = n - 1 ; i >= 0; i--){
        cout << a[i] << " ";
    }
    cout << endl;
}

int tichcacphantuChiaducho1e7(int a[100], int &n ){
    long long tich = 1;
    long long mod = 1e7;
    for(long long i = 1  ; i < n ; i++){
        tich *= a[i] % mod;
        tich %= mod;
    }
    return tich;
}

void countChanLe(int a[100], int n){
    int countChan = 0 ;  int countLe = 0 ;
        for(int i = 0 ; i < n; i++){
            if( a[i] % 2 == 0){
                countChan++;
            }
            else 
                countLe++;
        }
    cout << "So chan co trong la " << countChan << " so " << "\n" << "So le co trong mang la " << countLe << " so " << endl;
}

void TruyXuatPT(int a[100], int &n){
    cout <<"PT đầu tiên trong mảng: " << a[0]  << endl;
    cout << "PT cuối cùng trong mảng: " << a[n - 1] << endl;
    cout << "PT thứ 2 trong mảng: " << a[1] << endl;
    cout << "PT thứ 2 cuối cùng trong mảng: " << a[n - 2] << endl;
    if(n % 2 == 0){
        cout << "Invalid!" << endl;
    }
    else
        cout << "PT đứng giữa trong mảng: " << a[n/2] << endl;
}

int main(){
    int a[100], n;
    enterArray(a, n);
    printArray(a, n);
    cout << "Tich cac phan tu cua mang sau do chia cho 1e7 la: " << tichcacphantuChiaducho1e7(a, n ) << endl;
    countChanLe(a , n);
    TruyXuatPT(a, n);
    return 0;
}