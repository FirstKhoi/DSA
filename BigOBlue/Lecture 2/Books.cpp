#include <iostream>
#include <vector>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3809/problems/523?view=statement
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0, maxBooks = 0;
    long long sum = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right];
        while (sum > t) {
            sum -= a[left++];
        }
        if (right - left + 1 > maxBooks)
            maxBooks = right - left + 1;
    }
    cout << maxBooks << '\n';
    return 0;
}