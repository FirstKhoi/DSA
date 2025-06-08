#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3814/problems/533?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int max_height = 0;
    for (auto &p : freq) {
        max_height = max(max_height, p.second);
    }
    cout << max_height << " " << freq.size() << "\n";
    return 0;
}