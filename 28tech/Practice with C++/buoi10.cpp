#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

// Phan 1: De quy
int sum(int n) {
    if (n == 1) return 1;
    return n + sum(n - 1);
}

int sumSquare(int n) {
    if (n == 1) return 1;
    return n * n + sumSquare(n - 1);
}

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void reverseNumber(int n) {
    cout << n % 10;
    if (n >= 10) reverseNumber(n / 10);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int firstDigit(int n) {
    if (n < 10) return n;
    return firstDigit(n / 10);
}

int alternatingSum(int n) {
    if (n == 1) return -1;
    return (n % 2 == 0 ? n : -n) + alternatingSum(n - 1);
}

double harmonicSum(int n) {
    if (n == 1) return 1;
    return 1.0 / n + harmonicSum(n - 1);
}

long long combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

// Phan 2: Xu ly so va mang
bool allOddDigits(int n) {
    if (n == 0) return true;
    int d = n % 10;
    if (d % 2 == 0) return false;
    return allOddDigits(n / 10);
}

bool allEvenDigits(int n) {
    if (n == 0) return true;
    int d = n % 10;
    if (d % 2 != 0) return false;
    return allEvenDigits(n / 10);
}

int evenDigitSum(int n) {
    if (n == 0) return 0;
    return ((n % 10) % 2 == 0 ? n % 10 : 0) + evenDigitSum(n / 10);
}

int oddDigitSum(int n) {
    if (n == 0) return 0;
    return ((n % 10) % 2 != 0 ? n % 10 : 0) + oddDigitSum(n / 10);
}

int productDigits(int n) {
    if (n < 10) return n;
    return (n % 10) * productDigits(n / 10);
}

int countEven(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0) count++;
    return count;
}

int countOdd(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 != 0) count++;
    return count;
}

int sumEven(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0) sum += a[i];
    return sum;
}

int sumOddDigitsInArray(int a[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += oddDigitSum(a[i]);
    return total;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void printReverse(int a[], int n) {
    for (int i = n - 1; i >= 0; --i)
        cout << a[i] << " ";
    cout << endl;
}

int countDistinct(int a[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
        s.insert(a[i]);
    return s.size();
}

bool allNegative(int a[], int n) {
    for (int i = 0; i < n; ++i)
        if (a[i] >= 0) return false;
    return true;
}

int maxInArray(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > maxVal) maxVal = a[i];
    return maxVal;
}

bool isSymmetric(int a[], int n) {
    for (int i = 0; i < n / 2; ++i)
        if (a[i] != a[n - i - 1])
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}