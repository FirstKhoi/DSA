#include<bits/stdc++.h>
using namespace std;

bool mangDoiXung1(int a[], int n){
    for(int i =0 ;  i < n ; i ++){
        if( a[i] != a[ n - i - 1]){
            return false;
        }
    }
    return true;
}

bool mangDoiXung2(int a[], int n ){
    int l = 0, r = n - 1; 
    while ( l < r ){
        if( a[l] != a[r]){
            return false;
        }
    }
    return true;
}

void latMang(int a[], int n){
    for(int i = n - 1  ; i > n ; i--){
        cout << a[i] << endl;
    }
}

void latMang2(int a[], int n){
    for(int i = 0; i < n / 2 ; i++){
        swap(a[i], a[n - i - 1]);
    }
}

void latMang3(int a[], int n){
    int l = 0, r = n - 1;
    while ( l < r ){
        swap(a[l], a[n - 1]);
    }
}


