#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool nt(ll n ){
    for(int i = 2 ; i < sqrt(n) ; i++){
        if( n % i == 0 ){
            return false;
        }
    }
    return n > 1;
}


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

int main(){
    /*
    int n, a[100];
    cout << "Enter the number of array: "; cin >> n;
    for(int i = 0 ; i < n; ++i){
        cout << "a["<< i << "]= ";
        cin >> a[i];
    }

    //dạng 1: 
    for(int i = 1 ; i < n ; ++i){
        cout << 1ll * a[i] * a[ i - 1] << " " << endl;
}
    for(int i = 0 ; i < n ; i++){
        bool check = true;
        for(int j = 0 ; j < i ; j++){
            if( a[i] < a[j]){
                check = false; 
                break;
            }
        }
        if(check){
            cout << a[i] << " ";
        } 
    }

    for(int i =  0 ; i < n ; i++){
        bool check = true; 
        for(int j = j + 1 ; j < n; j++ ){
            if( a[j] > a[i]){
                check = false;
                break;
            }
        }
        if(check){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    for(int i = 0 ; i < n; i++){
        bool check = true;
        for(int j = 0 ; j < i  ; j++){
            if(a[i] == a[j]){
                check = false;
                break;
            }
        }
        if(check){
            cout << a[i] << " ";
        }
    }

    int count = 0 ;
    for(int i= 0 ; i < n; i++){
        bool check = true;
        for(int j = 0 ; j < i; j++){
            if(a[i] == a[j])
                check = false;
                break;
        }
        if(check){
            count++;
        }
    }
    cout << count << endl;


    for(int i = 0 ; i < n ; i++){
        bool check = true;
        for(int j = 0 ; j < i ; j++){
            if( a[i] == a[j]){
                check = false; 
                break;
            }
        }
        if (check){
            int tansuat = 1;
            for(int j = i + 1; j < n ; j++){
                if(a[i] == a[j]) ++tansuat;
            }
            cout << a[i] << " ";
        }
    }
    cout << endl;*/
    

    int n;
    cout << "Enter n: "; cin >> n;
    int a[n];
    for(int i =0 ; i < n ; i++){
        cin >> a[i];
    }

    //dạng 2
    //cân bằng nguyên tố
    for(int i = 0 ; i < n ; i++){
        int left = 0, right = 0 ;
        for(int j = 0 ; j < i ; j++){
            left += a[j];
        }
        for(int j = i + 1 ; j < n; j++){
            right += a[j];
        }
        if(nt(left) && nt(right)) cout << i << " ";
    }
    cout << endl;


    //số nhỏ nhất, A = {1,2,3,1,5} số nhỏ nhất là 1 xuất hiện 2 lần
    int minValue = a[0];
    int countMin = 1;
    for(int i = 1 ; i < n; i++){
        if(a[i] < minValue){
            minValue = a[i];
            countMin = 1;
        }else if(a[i] == minValue){
            countMin++;
        }
    }

    int maxValue = a[0];
    int countMax = 1;
    for(int i = 1 ; i < n; i++){
        if(a[i] > maxValue){
            maxValue = a[i];
            countMax = 1;
        }else if(a[i] == maxValue){
            countMax++;
        }
    }


    cout << "MinValue: " << minValue << "\n" << "Giá trị nhỏ nhất xuất hiện " << countMin << " lan" << "\n" << "Giá trị lớn nhất xuất hiện " << countMax << " lan" << "\n" << "MaxValue: " << maxValue << endl;

    //dạng 3
    //đếm cặp số 1, cho k, tìm các cộng số trong mảng cộng bằng k
    int k; cin >> k;
    int dem = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n; j++){
            if(a[i] + a[j] == k){
                ++dem;
            }
        }
    }
    cout << dem << endl;
    

    //đếm cặp số 2, tìm độ chênh lệch nhỏ nhất giữa 2 phần tử trong mảng
    int minVal = INT_MAX;
    for(int i =0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j ++){
            minVal = min(minVal, abs(a[i]- a[j]));
        }
    }
    cout << minVal << endl;

    //dạng 4
    //Fibonacci 1
    int m;
    cout << "Enter m: "; cin >> m;
    if(fibonacci(m))
        cout << "YES!" << endl;
    else
        cout << "NO!" << endl;

    //fibonacii chia lay du
    long long f[1000005];
    f[1] = 0;
    f[2] = 1;
    int mod = 1e7;
    for(int i = 3 ; i <= 1000000; i++){
        f[i] = f[i - 1] + f[ i - 2 ];
        f[i] %= mod;
    }
    cout << f[m] << endl;

    //fibonacci 3: liet ke fibonacci
    f[1] = 1;
    f[2] = 1; 
    for(int i = 3 ; i <= 92 ; i++){
        f[i] = f[ i - 1 ] + f[i - 2];
    }
    for(int i = 1 ; i <= m; i++){
        cout << f[i] << endl;
    }

    //fibonacci 5: check test case fibonacci
    int t;
    cout << "Enter the number of test cases: "; cin >> t;
    vector<long long> testcase(t);
    for(int i = 0; i < t; ++i){
        cin >> testcase[i];
    }
    for(int i = 0 ; i < t ;i++){
        if(fibonacci(m)){
            cout << "Yes!" << endl;
        }
        else 
            cout << "NO!" << endl;
    }
    return 0;
}

