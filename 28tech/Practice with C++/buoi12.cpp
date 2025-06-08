#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/* Cho một mảng gồm n (3<=n<=100000) số nguyên đôi một khác nhau, tìm
và
in ra 3 số lớn nhất trong mảng.
Ví dụ
Input
10
99 13 2 4 0 12 24 58 56 14
Output
99 58 56    */
void bai1(int  n, int a[]){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max1 = -1e9, max2 = -1e9, max3 = -1e9;
    for(int i = 0; i < n; i++){
        if(a[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2){
            max3 = max2;
            max2 = a[i];
        }
        else if(a[i] > max3){
            max3 = a[i];
        }
    }
    cout << max1 << " " << max2 << " " << max3 << endl;
}

/*Cho một mảng gồm n (3<=n<=100000) số nguyên đôi một khác nhau, liệt kê
các phần tử trong mảng có ít nhất 2 phần tử khác lớn hơn nó.
Ví dụ
Input
6
1 5 4 3 2 7
Output
1 4 3 2     */
void bai2(int n, int a[]){
    cin >> n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a[10000];
    bai1(n, a);
    return 0;
}