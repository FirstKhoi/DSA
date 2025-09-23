#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//https://codeforces.com/contest/22/problem/A
int main() {
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    if(s.size() < 2) {
        cout << "NO" << endl;
    } else {
        auto it = s.begin();
        ++it;
        cout << *it << endl;
    }
    return 0;
}