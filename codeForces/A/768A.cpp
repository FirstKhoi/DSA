#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/768/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int minVal = a[0], maxVal = a[n-1];
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > minVal && a[i] < maxVal) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}