#include<bits/stdc++.h>
using namespace std;

int SumN(int n){
    int Sum = 0;
    for(int i = 0 ; i <= n ; i++){
        Sum +=i;
    }
    return Sum;
}

int SumPow2(int n){
    int Sum = 0;
    for(int i = 0 ; i <= n ; i++){
        Sum += i * i; 
    }
    return Sum;
}

int CountDigit(int n){
    if (n == 0) {
        return false;
    }
    int count = 0;
    while(n > 0){
        n /= 10;
        count++;
    }

    return count;
}

int CountDigitandSumDigit(int n){
    if (n == 0) {
        return false;
    }
    int sum = 0, count = 0;
    while(n > 0){
       sum += n%10;
       n /= 10;
    }
    return sum;
}

int CountDigitofPrimeNum(int n) {
    int count = 0, sum = 0;
    while (n > 0) {
        int r = n % 10;
        if( r == 2 || r == 3 || r == 5 || r ==7){
            count++;
        } 
        n /= 10;
    }
    return count;
}

int findMaxDigit(int n){
    int temp;
    temp = n % 10;
    while( n > 0){
        if( n % 10 > temp){
            temp = n % 10;
        }
        n /= 10;
    }
    return temp;
}

void findMinDigit(int n){
    int temp;
    temp = n % 10;
    while(n > 0){
        if(n % 10 < temp){
            temp = n % 10;
        }
        n /= 10;
    }
   cout << "Minimum number of digit is: " << temp << endl;
}

int main(){
    int n;
    cout << "Enter n: "; cin >> n;
   
    cout << "Sum 1 to " << n << " is: " << SumN(n) << endl;
   
    cout << "Sum of pow 1 to " << n << " is : " << SumPow2(n) << endl;

    if(n == false){
        cout << n << " contains 1 digit!" << endl;
    } else
    cout << n <<" contains " <<   CountDigit(n)  << " digits!" << endl;

    if(n == false){
        cout << "Sum = 0 " << endl;
    }
    else
    cout << "Cause the " << n << " has " << CountDigit(n) << " digits so sum of them equal " << CountDigitandSumDigit(n) << endl;
    
    cout << n << " contains " << CountDigitofPrimeNum(n) << " prime digits!" << endl;

    cout << "Maximum number of digit is: " << findMaxDigit(n) << endl;  findMinDigit(n);


    return 0; 
}