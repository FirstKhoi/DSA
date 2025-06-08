#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;

        int l = 0, r = 1;
        while(r < n){
            if(nums[l] != nums[r]){
                l++;
                nums[l] = nums[r];
            }
            r++;
        }
        return l + 1;
    }
};
    return 0;
}