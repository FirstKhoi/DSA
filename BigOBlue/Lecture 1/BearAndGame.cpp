#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3808/problems/528?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    int lastInterestingMinute = 0;
    int currentTime = 0;
    
    for(int i = 0; i < n; ++i){
        int minute; cin >> minute;
        if(minute - lastInterestingMinute > 15){
            currentTime = lastInterestingMinute + 15;
            cout << currentTime;
            return 0;
        }
        
        lastInterestingMinute = minute;
    }
    
    cout << min(lastInterestingMinute + 15, 90);
    
    return 0;
}
