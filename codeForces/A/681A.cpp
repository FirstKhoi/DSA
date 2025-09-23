#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/681/problem/A

int main() {
    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    bool found = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] >= 2400 && b[i] > a[i]) {
            found = true;
        }
    }
    cout << (found ? "YES" : "NO") << endl;
    return 0;
}