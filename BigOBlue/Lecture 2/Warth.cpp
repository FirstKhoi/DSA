#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3809/problems/1056?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int count = 0;
    int j = n - 1;
    
    for(int i = n - 1; i >= 0; i--){
        j = min(j, i);
        int lastKill = max(0, i - a[i]);
        
        if(j > lastKill) {
            count += (j - lastKill);
            j = lastKill;
        }
    }
    
    cout << n - count << endl;
    return 0;
}