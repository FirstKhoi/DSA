#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int count = 0;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), a[i] + k);
        if(it != a.end() && *it == a[i] + k) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}