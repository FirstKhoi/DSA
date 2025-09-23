#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int len = 2 * n + 1;
    vector<int> r(len), y(len);

    for (int i = 0; i < len; ++i) {
        cin >> r[i];
    }

    int count = 0;

    for (int i = 1; i < len - 1; i += 2) { // i = 2, 4, ..., 2n (even index)
        if (r[i] > r[i - 1] && r[i] > r[i + 1] && count < k) {
            y[i] = r[i] - 1; // giảm đỉnh này
            count++;
        } else {
            y[i] = r[i]; // giữ nguyên
        }
    }

    // Các vị trí còn lại (lẻ): giữ nguyên
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) y[i] = r[i];
    }

    // In kết quả
    for (int i = 0; i < len; ++i) {
        cout << y[i] << " ";
    }
    cout << endl;

    return 0;
}
