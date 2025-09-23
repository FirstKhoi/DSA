#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    vector<int> prefixOnes(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefixOnes[i] = prefixOnes[i-1] + arr[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int ones = prefixOnes[r] - prefixOnes[l-1];
        
        int zeros = (r - l + 1) - ones;
    
        int xorResult = ones % 2;
        
        cout << xorResult << " " << zeros << "\n";
    }
    
    return 0;
}