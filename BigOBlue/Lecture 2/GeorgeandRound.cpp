#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3809/problems/522?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(b[j] >= a[i]) {
            i++;
        }
        j++;
    }

    cout << n - i << '\n';
    return 0;
}