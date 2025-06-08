#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0;
        for(int i = 0; i < n && j < m; ++i){
            if(s[i] == t[j]){
                j++;
            }
        }
        return m - j;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}