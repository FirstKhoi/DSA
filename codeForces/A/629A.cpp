#include<iostream>
#include<vector>
using namespace std;
//http://codeforces.com/contest/629/problem/A
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> cake(n);
    for(int i = 0; i < n; i++) {

            cin >> cake[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        int countR = 0;
        for(int j = 0; j < n; j++) {
            if(cake[i][j] == 'C') countR++;
        }
        count += countR * (countR - 1) / 2;
    }

    for(int j = 0; j < n; j++) {
        int countC = 0;
        for(int i = 0; i < n; i++) {
            if(cake[i][j] == 'C') countC++;
        }
        count += countC * (countC - 1) / 2;
    }
    cout << count << endl;
}