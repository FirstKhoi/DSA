#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/lexicographically-smallest-palindrome/submissions/1644579540/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n/2; ++i) {
            if (s[i] != s[n-1-i]) {
                s[i] = s[n-1-i] = min(s[i], s[n-1-i]);
            }
        }
        return s;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}