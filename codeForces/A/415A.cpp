#include<iostream>
#include<vector>
using namespace std;
//https://codeforces.com/contest/415/problem/A
int main() {
    int n, m; cin >> n >> m;
    vector<int> buttons(m);
    vector<int> res(n, 0);

    for(int i = 0; i < m; i++) {
        cin >> buttons[i];
    }
    
    for(int i = 0; i < m; i++) {
        int b = buttons[i];
        for(int j = b - 1; j < n; j++) {
            if(res[j] == 0) {
                res[j] = b;
            }
        }
    }
    //print res
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}