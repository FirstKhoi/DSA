#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/reverse-string/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}