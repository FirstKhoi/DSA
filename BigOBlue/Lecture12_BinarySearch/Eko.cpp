#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int hMin = 0, hMax = 1e9 + 7;
    long long sum = 0;
    int res;

    while(hMin <= hMax) {
        int mid = hMin + (hMax - hMin) / 2;
        
        sum = 0;
        for(int &x : a) {
            sum += max(0, x - mid);
        }

        if(sum >= m) {
            res = mid;
            hMin = mid + 1;
        } else {
            hMax = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}