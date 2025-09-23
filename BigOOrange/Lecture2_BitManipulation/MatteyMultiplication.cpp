#include <iostream>
#include <vector>
using namespace std;

void multiply(long long n, long long m) {
    if(m == 0) {
        cout << "0" << endl;
        return;
    }
    
    vector<int> shifts;
    int shift = 0;
    
    while(m > 0) {
        if(m & 1) {
            shifts.push_back(shift);
        }   
        m >>= 1;
        shift++;
    }
    
    for(int i = shifts.size()-1; i >= 0; i--) {
        if(i != shifts.size()-1) cout << " + ";
        cout << "(" << n << "<<" << shifts[i] << ")";
    }
    cout << endl;
}

int main() {
    int T; 
    cin >> T;
    while(T--) {
        long long n;
        long long m;
        cin >> n >> m;
        multiply(n, m);
    }
    return 0;
}