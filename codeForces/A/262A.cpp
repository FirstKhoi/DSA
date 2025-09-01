#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/262/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int temp = a[i];
        int count = 0;
        while(temp > 0) {
            int digit = temp % 10;
            if(digit == 4 || digit == 7) count++;
            temp /= 10;
        }
        if(count <= k) res++;
    }
    cout << res << endl;
}