#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/reverse-string-ii/description/?envType=problem-list-v2&envId=2fh4qdsc
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    string reverseStr(string s, int k) {
        int l = 0;
        int r = min(k, (int)s.length());
        while(l < s.length()){
            reverse(s.begin() + l, s.begin() + r);
            l += 2*k;
            r = min(l + k, (int)s.length());
        }
        return s;
    }
};
    return 0;
}