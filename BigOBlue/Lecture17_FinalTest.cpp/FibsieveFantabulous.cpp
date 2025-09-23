#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int T, tc = 1;
    cin >> T;
    while(T--) {
        long long s; cin >> s;
        long long k = ceil(sqrt((long double)s));
        long long k2 = k * k;
        long long d = k2 - s;
        
        long long x, y;
        if(d < k) {
            if(k % 2 == 1) {
                x = k;
                y = d + 1;
            } else {
                x = d + 1;
                y = k;
            }
        } else {
            if(k % 2 == 1) {
                x = 2*k - d - 1;
                y = k;
            } else {
                x = k;
                y = 2*k - d - 1;
            }
        }
        cout << "Case " << tc++ << ": " << y << " " << x << endl; 
    }
    return 0;
}