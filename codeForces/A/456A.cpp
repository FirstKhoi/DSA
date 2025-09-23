#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://codeforces.com/contest/456/problem/A
int main() {
    // a < a(i+1) && b > b(i + 1)
    int n; cin >> n;
    vector<pair<int, int>> laptops(n);
    
    for(int i = 0; i < n; i++) {
        cin >> laptops[i].first >> laptops[i].second;
    }
    sort(laptops.begin(), laptops.end());

    for(int i = 0; i < n - 1; i++) {
        if(laptops[i].second > laptops[i + 1].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}