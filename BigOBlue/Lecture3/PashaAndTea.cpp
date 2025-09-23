#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/531?view=statement 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;
    vector<int> a(2 * n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    double minG = a[0];
    double minB = a[n];
    double x = min(minG, minB / 2.0);
    double total = min(3.0 * n * x, double(w));
    cout << fixed << setprecision(9) << total << '\n';
    return 0;
}