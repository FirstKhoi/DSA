#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/remove-element/?envType=problem-list-v2&envId=2fh4qdsc
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0; 
        for (int r = 0; r < n; r++) {
            if (nums[r] != val) {
                nums[l] = nums[r]; 
                l++; 
            }
        }
        return l; 
    }
};    
    return 0;
}