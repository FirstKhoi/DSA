#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/721/problem/A

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> segments;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            count++;
        } else {
            if(count > 0) {
                segments.push_back(count);
                count = 0;
            }
        }
    }
    if(count > 0) segments.push_back(count);
    cout << segments.size() << endl;
    for(int i = 0; i < segments.size(); i++) {
        cout << segments[i] << " ";
    }
    return 0;
}