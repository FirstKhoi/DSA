#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/296/problem/A
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n < 2) {
        cout << "YES" << endl;
        return 0;
    }
    vector<int> freq(101, 0);
    int maxFreq = 0;
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
        if(freq[a[i]] > maxFreq) maxFreq = freq[a[i]];
    }
    if(maxFreq <= (n + 1) / 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}