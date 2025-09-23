#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/365/problem/A
bool hasAllDigits(int num, int k) {
    vector<bool> found(k + 1, false);
    while (num > 0) {
        int digit = num % 10;
        if (digit <= k) found[digit] = true;
        num /= 10;
    }
    for (int d = 0; d <= k; ++d) {
        if (!found[d]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(hasAllDigits(a[i], k)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}