#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/count-binary-substrings/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int n = s.size();
        int l = 0, mid = 0, r = 0;
        while (l < n) {
            mid = l;
            while (mid < n && s[mid] == s[l]) {
                mid++;
            }
            r = mid;
            while (r < n && s[r] != s[l]) {
                r++;
            }
            count += min(mid - l, r - mid);
            l = mid;
        }
        return count;
        
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string s = "00110011";
    cout << sol.countBinarySubstrings(s) << endl; // Output: 6
    return 0;
}