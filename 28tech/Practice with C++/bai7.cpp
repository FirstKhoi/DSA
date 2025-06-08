#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*Input 
5 
Output
10101
01010
10101
01010
10101   */
void bai1(int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cout << ((i + j) % 2);
        }
        cout << endl;
    }
    cout << endl;
}

/*Input   Output
    5   1 2 3 4 5
        2 3 4 5 6
        3 4 5 6 7
        4 5 6 7 8
        5 6 7 8 9   */
void bai2( int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= n; j++){
            cout << i + j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
Input Output
5   1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25  */
void bai3(int n){
    int count = 0; 
    for(int i = 1; i <= n ;i++){
        for(int j= 1; j <= n; j++){
            count++;
            cout << count <<" ";
        }
        cout << endl;
    }
    cout << endl;
}


/*
Input  Output
5       ~~~~1
        ~~~22
        ~~333
        ~4444
        55555   */
void bai4(int n){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1  ; j <= n - i ; j++){
            cout << "~";
        }
        for(int j = 1; j <= i; j++){
            cout << i;
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bai1(5);   
    bai2(5);
    bai3(5);
    bai4(5);
    return 0;
}