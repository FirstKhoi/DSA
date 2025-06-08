#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/reverse-words-in-a-string-iii/description/?envType=problem-list-v2&envId=2fh4qdsc
int main(){
    ios::sync_with_stdio(0);
   cin.tie(nullptr);
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        for(int end = 0; end < n; end++){
            if(s[end] == ' ' || end == n - 1){
                int wordEnd = (s[end] == ' ') ? end - 1 : end;
            
                int left = start;
                int right = wordEnd;
                while(left < right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                start = end + 1;
            }
        }
        return s;
    }
};
    return 0;
}