#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3809/problems/521?view=statement
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    unordered_map<int, int> cnt;
    int unique = 0, left = 0;
    for(int right = 0; right < n; ++right) {
        if(cnt[a[right]]++ == 0) unique++;
        while(unique > k) {
            if(--cnt[a[left]] == 0) unique--;
            left++;
        }
        if(unique == k) {
            // Thu nhỏ cửa sổ bên trái nếu có thể
            while(cnt[a[left]] > 1) {
                cnt[a[left]]--;
                left++;
            }
            cout << left + 1 << " " << right + 1 << endl;
            return 0;
        }
    }
    cout << "-1 -1\n";
    return 0;
}
