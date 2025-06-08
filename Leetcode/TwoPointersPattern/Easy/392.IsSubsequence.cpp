#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/is-subsequence/description/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int n = s.size(), m = t.size();
        while (i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == n) return true;
        return false;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    bool result = sol.isSubsequence(s, t);
    cout << (result ? "True" : "False") << endl;
    return 0;
}