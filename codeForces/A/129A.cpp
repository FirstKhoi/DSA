#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int total = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    
    int count = 0;

    for(int i = 0; i < n; i++) {
        if((total - a[i]) % 2 == 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}