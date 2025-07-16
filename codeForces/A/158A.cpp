#include <iostream>
#include <vector>
using namespace std;

// https://codeforces.com/contest/158/problem/A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    int threshold = (k > 0) ? a[k - 1] : 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= threshold && a[i] > 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}