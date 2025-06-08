#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3808/problems/487?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    int count1 = 0;
    int count0 = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == 1)
            count1++;
        else count0++;
    }   
    if(n == 1){
        if(count1 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else{
        if(count0 == 1 && count1 == n - 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}