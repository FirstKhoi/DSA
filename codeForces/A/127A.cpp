#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/127/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    double length = 0.0;
    for(int i = 0; i < n - 1; i++) {
        int dx = points[i + 1].first - points[i].first;
        int dy = points[i + 1].second - points[i].second;
        length += sqrt(dx * dx + dy * dy);
    }
    double time = (length * k) / 50.0;
    cout << fixed << setprecision(10) << time << endl;
    return 0;
}