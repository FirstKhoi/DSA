#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/remove-palindromic-subsequences/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int removePalindromeSub(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return 2;
            }
            l++;
            r--;
        }
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}