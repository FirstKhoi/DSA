#include <iostream>
using namespace std;
//https://codeforces.com/contest/707/problem/A
int main() {
    int n, m;
    cin >> n >> m;
    bool isColor = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string pixel;
            cin >> pixel;
            if (pixel == "C" || pixel == "M" || pixel == "Y") {
                isColor = true;
            }
        }
    }
    cout << (isColor ? "#Color" : "#Black&White") << endl;
    return 0;
}