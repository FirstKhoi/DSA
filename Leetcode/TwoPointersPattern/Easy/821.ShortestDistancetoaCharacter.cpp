#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> result(n, INT_MAX);
    
        int prev = -n; 
        for (int i = 0; i < n; i++) {
            if (s[i] == c)
                prev = i;
            result[i] = i - prev;
        }
        
        // Right to left pass
        prev = 2 * n; // Initialize with a large positive value
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c)
                prev = i;
            result[i] = min(result[i], prev - i);
        }
        
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}