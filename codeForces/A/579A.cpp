#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x; cin >> x;
    int count = 0;
    while(x > 0) {
        count += x % 2;
        x /= 2;
    }
    cout << count << endl;
    return 0;
}