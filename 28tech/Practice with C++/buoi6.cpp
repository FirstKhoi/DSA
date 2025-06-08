#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*Viết chương trình C cho phép nhập vào hàng và cột của hình bình hành. Thực hiện
in hình bình hành sao.
INPUT
3 4
OUTPUT
****
~*..*
~~*****/
void bai1(int c, int r){
    for(int i = 0 ; i < c ; i++){
        for(int j = 0 ; j < i; j++){
            cout << "~";
        }
        if(i == 0 || i == c - 1){
            for(int j = 0 ; j < r ; j++){
                cout << "*";
            }
        }
        else{
            if(r >= 2){
                cout << "*";
                for(int j = 0; j < r - 2; j++){
                    cout << ".";
                }
                cout << "*";
            }
            else cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}


/*Viết chương trình C cho phép nhập vào số hàng và cột của hình chữ nhật và in ra
hình chữ nhật các số
tương ứng.
INPUT
5 5
OUTPUT
11111
11111
11111
11111
11111*/
void bai2(int c, int r){
    for(int i = 0 ; i <= c; i++){
        for(int j = 0 ; j <= r; j++){
            cout << "1";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào n là độ dài cạnh hình bình hành. Thực
hiện in ra hình bình hành
tương ứng.
INPUT 5
OUTPUT
~~~~*****
~~~*****
~~*****
~*****
***** */
void bai3(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1; j++){
            cout << "~";
        }
        for(int j = 0 ; j < n ; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào chiều cao của tam giác và thực hiện in ra
tam giác sao ngược rỗng
INPUT
5
OUTPUT
*****
*..*
*.*
**
* */
void bai4(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i; j++){
            if( i == 0 || j == 0 || j == n - i - 1){
                cout << "*";
            }
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}
/*Viết chương trình C nhập vào số cột của một nửa hình thoi bên phải và in ra hình
tương ứng.
INPUT
5
OUTPUT
*
**
***
****
*****
****
***
**
*     */
void bai5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1 ;  j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n - 1; i >= 1 ;i--){
        for(int j = 1; j <= i ;j++){
             cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào chiều cao của tam giác và thực hiện in ra
tam giác vuông sao ngược phải.
INPUT
5
OUTPUT
*****
~****
~~***
~~~**
~~~~*   */
void bai6(int n){
    for(int i = 0 ; i < n ;i++){
        for(int j = 0; j < i; j++){
            cout << "~";
        }
        for(int j = 0 ; j < n - i; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào số hàng và cột của hình chữ nhật và in
ra hình chữ nhật các số tương ứng.
INPUT
5 5
OUTPUT
11111
00000
11111
00000
11111  */
void bai7(int c, int r){
    for(int i = 0; i <= c ; i++){
        for(int j = 0 ; j <= r; j++){
            if(i == 0 || i == 2 || i == 4){
                cout << "1";
            }
            else
                cout << "0";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào chiều cao của tam giác và thực hiện in ra
tam giác vuông sao ngược phải rỗng
INPUT
5
OUTPUT
*****
~*..*
~~*.*
~~~**
~~~~*   */
void bai8(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < i; j++){
            cout <<".";
        }
        for(int j = 0; j <  n - i; j++){
            if(j == 0 || j == n - i - 1 || i == 0 || i == n -1){
                cout << "*";
            }
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình nhập vào n và in ra hình theo quy luật
INPUT
5
OUTPUT
12345
678910
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25*/
void bai9(int n){
    int count = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
    cout << endl;
}


/*Viết chương trình C cho phép nhập vào n là cạnh của hình vuông và thực hiện in ra
hình vuông rỗng các ký tự *.
INPUT
4
OUTPUT
****
*..*
*..*    */
void bai10(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

/*Viết chương trình nhập vào n và in ra hình theo quy luật
INPUT
5
OUTPUT
12345
21234
32123
43212
54321   */
void bai11(int n){
    int count1 = 0;
    for(int i = 1; i <= n ; i++){
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        for(int j = 2 ; j <= n - i + 1; j++){
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

/*Viết chương trình C cho phép nhập vào chiều cao của tam giác và In ra tam giác
hình sao rỗng tương ứng.
INPUT
5
OUTPUT
*
**
*.*
*..*
*****   */
void bai12(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= i ; j++){
            if( j == 1 || j == i || i == n)
                cout << "*";
            else    cout <<".";
        }
        cout << endl;
    }
    cout << endl;
}
    
/*Viết chương trình cho phép nhập vào số n và in ra hình thoi tương ứng với n.
INPUT
5
OUTPUT
~~~~*
~~~***
~~*****
~*******
*********
~*******
~~*****
~~~***
~~~~**/
void diamond(int n) {
    for (int i = 0; i < n; ++i) {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; ++j) {
            cout << '~';
        }
        // Print stars with separation
        for (int k = 0; k <= 2 * i; ++k) {
            if (k % 2 == 0 || k == 0 || k == 2 * i) {
                cout << '*';
            } else {
                cout << '~';
            }
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 0; --i) {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; ++j) {
            cout << '~';
        }
        // Print stars with separation
        for (int k = 0; k <= 2 * i; ++k) {
            if (k % 2 == 0 || k == 0 || k == 2 * i) {
                cout << '*';
            } else {
                cout << '~';
            }
        }
        cout << endl;
    }
}


void bai13(int n){
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n - i; j++){
            cout << "~";
        }
        for(int j = 1 ; j <= 2 * i - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n - 1; i >= 1 ; i--){
        for(int j = 1 ; j <= n - i; j++){
            cout << "~";
        }
        for(int j = 1 ; j <= 2 * i - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bai1(3,4);  
    bai2(5,5);
    bai3(5);
    bai4(5);
    bai5(5);
    bai6(5);
    bai7(5,5);
    bai8(5);
    bai9(5);
    bai10(4);
    bai11(5);
    bai12(5);
    bai13(5);
    diamond(5);
    return 0;
}   