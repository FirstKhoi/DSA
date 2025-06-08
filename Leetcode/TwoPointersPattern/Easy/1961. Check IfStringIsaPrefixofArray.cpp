#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/?envType=problem-list-v2&envId=two-pointers
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int sPointer = 0;
        int wPointer = 0;
        while(sPointer < n && wPointer < m){
            string currentWords = words[wPointer];
            int wordLen = currentWords.length();
            if(sPointer + wordLen > n){
                return false;
            }
            bool match = true;
            for(int i = 0; i < wordLen; i++){
                if(s[sPointer + i] != currentWords[i]){
                    match = false;
                    break;
                }
            }
            if(!match){
                return false;
            }
            sPointer += wordLen;
            wPointer++;
        }
        return sPointer == n;
    }
};  
    return 0;
}