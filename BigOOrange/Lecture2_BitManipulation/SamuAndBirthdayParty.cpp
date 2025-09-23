#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countBits(int x) {
    int count = 0;
    while (x) {
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> likes(N, 0);
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            int mask = 0;
            for (int j = 0; j < K; ++j) {
                if (s[j] == '1') {
                    mask |= (1 << j);
                }
            }
            likes[i] = mask;
        }

        int min_dishes = K;
        for (int subset = 1; subset < (1 << K); ++subset) {
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                if ((likes[i] & subset) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int cnt = countBits(subset);
                if (cnt < min_dishes) min_dishes = cnt;
            }
        }
        cout << min_dishes << endl;
    }
    return 0;
}